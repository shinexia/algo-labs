#define _GNU_SOURCE

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s ip port\n", argv[0]);
        exit(-1);
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int sockfd;
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "create socket fd failed, msg: %s\n", strerror(errno));
        exit(-1);
    }
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "bind failed, msg: %s\n", strerror(errno));
        close(sockfd);
        exit(-1);
    }
    if ((listen(sockfd, 5)) == -1) {
        fprintf(stderr, "listen failed, msg: %s\n", strerror(errno));
        close(sockfd);
        exit(-1);
    }
    for (;;) {
        printf("waiting for connection\n");
        struct sockaddr_in client;
        socklen_t client_addr_length = sizeof(client);
        int connfd;
        if ((connfd = accept(sockfd, (struct sockaddr*)&client,
                             &client_addr_length)) < 0) {
            fprintf(stderr, "accept failed, msg: %s\n", strerror(errno));
            close(sockfd);
            exit(-1);
        }
        printf("accepted connection\n");
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            fprintf(stderr, "pipe fd failed, msg: %s\n", strerror(errno));
            close(sockfd);
            close(connfd);
            exit(-1);
        }
        int n;
        for (;;) {
            if ((n = splice(connfd, NULL, pipefd[1], NULL, 32768,
                            SPLICE_F_MOVE | SPLICE_F_MORE)) == -1) {
                fprintf(stderr, "splice connfd failed, msg: %s\n",
                        strerror(errno));
                close(connfd);
                close(sockfd);
                exit(-1);
            }
            fprintf(stderr, "recv %d bytes\n", n);
            if (n == 0) {
                break;
            }
            if (splice(pipefd[0], NULL, connfd, NULL, 32768,
                       SPLICE_F_MOVE | SPLICE_F_MORE) == -1) {
                fprintf(stderr, "splice out fd failed, msg: %s\n",
                        strerror(errno));
                close(connfd);
                close(sockfd);
                exit(-1);
            }
        }
        close(connfd);
        printf("connection closed\n");
    }
    close(sockfd);
    printf("program exited\n");
    exit(0);
}
