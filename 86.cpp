#include "a.h"
#include "template/list.h"

ListNode* partition(ListNode* head, int x) {
    auto* node = new ListNode(-10000);
    node->next = head;
    // 先找一个

    auto ptr = node;
    while (true) {
        if (ptr && ptr->val < x && ((!ptr->next) || ptr->next->val >= x)) break;
        ptr = ptr->next;
    }

    dbg(ptr->val);

    auto it = ptr->next;
    auto last = it;
    while (it) {
        if (it->val < x) {
            dbg(it->val);
            auto* x = it;
            // remove
            last->next = x->next;

            //
            x->next = ptr->next;
            ptr->next = x;
            ptr = x;
        }

        last = it;
        it = it->next;
    }

    auto* res = node->next;
    delete node;
    return res;
}

int main() {
    auto* list = vecToList({2, 1, 1, 1, 1});

    printList(partition(list, 2));
    return 0;
}
