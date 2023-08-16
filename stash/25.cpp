#include <stdio.h>

#include <cassert>

#include "a.h"
#include "template/list.h"

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return nullptr;
    auto* ptr = head;
    for (int i = 0; i < k - 1; i++) {
        if (!ptr) return head;  // 不足K个节点，直接返回
        ptr = ptr->next;
    }
    // 不足K个节点，直接返回
    if (!ptr) return head;

    // 反转链表
    ListNode* nh{nullptr};
    auto* ptr2 = head;
    do {
        auto* next = ptr2->next;
        ptr2->next = nh;
        nh = ptr2;
        ptr2 = next;
    } while (ptr2 != ptr);

    assert(ptr2 == ptr);

    auto* last = ptr->next;
    ptr->next = nh;
    head->next = reverseKGroup(last, k);
    return ptr;
}

int main() {
    auto* list = vectoToList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    printList(list);
    printf("\n-----------------------\n");
    auto* res = reverseKGroup(list, 4);
    printList(res);
    return 0;
}
