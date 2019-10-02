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

int hexdump(char* dest, int dest_off, char* src, int src_off, int size) {
    char* d = dest + dest_off;
    int di = 0;
    for (int si = src_off; si < src_off + size; si++) {
        if (si != src_off) {
            d[0] = ' ';
            d += 1;
            di += 1;
        }
        sprintf(d, "%02X", src[si]);
        d += 2;
        di += 2;
    }
    d[0] = '\0';
    return di;
}

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
        char buf[4096];
        char pb[4096 * 3];
        for (;;) {
            int read = recv(connfd, buf, 4096, 0);
            int hlen = hexdump(pb, 0, buf, 0, read);
            printf("recv %d bytes:%.*s\n", read, hlen, pb);
            if (!read) {
                break;
            }
            if (send(connfd, buf, read, 0) != read) {
                fprintf(stderr, "send failed, msg: %s\n", strerror(errno));
                close(connfd);
                close(sockfd);
                exit(-1);
            }
        }
        close(connfd);
        printf("connection closed\n");
    }
    close(sockfd);
    printf("program exited");
    exit(0);
}
