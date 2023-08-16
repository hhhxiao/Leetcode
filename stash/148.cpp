#include <stdint.h>
#include <stdio.h>

#include <cassert>
#include <type_traits>
#include <vector>

#include "template/list.h"

ListNode* merge(ListNode* a, ListNode* b) {
    auto* p1 = a;
    auto* p2 = b;

    ListNode* head{nullptr};
    ListNode* tail{nullptr};

    while (p1 || p2) {
        ListNode* handler{nullptr};
        if (p1 && (!p2)) handler = p1;
        if (p2 && (!p1)) handler = p2;
        if (p1 && p2) handler = p1->val < p2->val ? p1 : p2;
        auto nx = handler->next;
        if (!head) {
            head = tail = handler;
        } else {
            tail->next = handler;
            tail = handler;
            tail->next = nullptr;
        }
        // step

        if (handler == p1) p1 = nx;
        if (handler == p2) p2 = nx;
    }
    return head;
}

ListNode* sort(ListNode* begin, ListNode* end, int len) {
    assert(begin && end);
    if (begin == end) return begin;
    int half = len >> 1;
    auto* mid = begin;
    for (int i = 0; i < half - 1; i++) mid = mid->next;
    auto* b2 = mid->next;
    mid->next = nullptr;

    auto* a = sort(begin, mid, half);
    auto* b = sort(b2, end, len - half);

    // return begin;
    return merge(a, b);
}

ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;
    auto* pt = head;
    int n = 1;
    while (pt->next) {
        pt = pt->next;
        n++;
    }
    return sort(head, pt, n);
}

int main() {
    std::vector<int> v{2, 1};
    auto* list = vectoToList(v);
    auto* res = sortList(list);
    printList(res);

    // auto* a = vectoToList({1, 3, 5, 6});
    // auto* b = vectoToList({2, 4, 8, 9, 10, 11, 12});
    // printList(merge(a, b));
    return 0;
}