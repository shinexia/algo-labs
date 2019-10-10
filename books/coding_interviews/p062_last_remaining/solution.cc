#include "solution.h"
#include <memory>
#include "mylib/util.h"

namespace {

struct ListNode;
typedef ListNode* ListNodePtr;

struct ListNode {
    uint32_t Val = 0;
    ListNodePtr Next = nullptr;

    ListNode(uint32_t v) : Val(v) {}
};

ListNodePtr NewCircle(uint32_t n) {
    if (n < 1) {
        return nullptr;
    }
    ListNodePtr head = new ListNode(0);
    ListNodePtr tail = head;
    for (int i = 1; i < n; ++i) {
        ListNodePtr next = new ListNode(i);
        tail->Next = next;
        tail = next;
    }
    tail->Next = head;
    return tail;
}

void DeleteCircle(ListNodePtr head) {
    if (head == nullptr) {
        return;
    }
    ListNodePtr tail = head->Next;
    while (tail != head) {
        ListNodePtr next = tail->Next;
        delete tail;
        tail = next;
    }
    delete head;
}

}  // namespace

int BruteForce_LastRemaining(uint32_t n, uint32_t m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    ListNodePtr prev = NewCircle(n);
    int remainCount = n;
    ListNodePtr head = prev->Next;
    while (remainCount > 1) {
        for (int i = 1; i < m; ++i) {
            prev = head;
            head = head->Next;
        }
        prev->Next = head->Next;
        ListNodePtr t = head;
        head = head->Next;
        delete t;
        --remainCount;
    }
    int result = head->Val;
    delete head;
    return result;
}

int LastRemaining(uint32_t n, uint32_t m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    int num = 0;
    for (int i = 2; i <= n; ++i) {
        num = (num + m) % i;
    }
    return num;
}
