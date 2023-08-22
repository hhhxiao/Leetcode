#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void printList(ListNode *head) {
    if (head) {
        printf("%d -> ", head->val);
        printList(head->next);
    } else {
        printf("null");
    }
}

inline ListNode *vecToList(const std::vector<int> &list) {
    if (list.empty()) return nullptr;
    ListNode *head = new ListNode(list[0]);
    ListNode *ptr = head;
    for (int i = 1; i < list.size(); i++) {
        ptr->next = new ListNode(list[i]);
        ptr = ptr->next;
    }

    return head;
}
