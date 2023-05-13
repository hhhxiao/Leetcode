#include <vector>

#include "template/list.h"

ListNode* merge(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    ListNode* head = nullptr;
    ListNode* ptr = head;

    ListNode* pa = a;
    ListNode* pb = b;

    while (pa || pb) {
        if (pa && pb) {
            if (pa->val < pb->val) {
                if (head) {  //已经有头了
                    ptr->next = pa;
                    ptr = ptr->next;
                } else {
                    head = pa;
                    ptr = pa;
                }

                pa = pa->next;
            } else {
                if (head) {
                    ptr->next = pb;
                    ptr = ptr->next;
                } else {
                    head = pb;
                    ptr = pb;
                }

                pb = pb->next;
            }
        } else if (pa) {
            ptr->next = pa;
            break;
        } else if (pb) {
            ptr->next = pb;
            break;
        }
    }
    return head;
}

void mergeTwo(std::vector<ListNode*>& l, int begin, int end) {
    printf("Merge [%d %d)\n", begin, end);
    int len = end - begin;
    if (len == 2) {
        //合并
        //把第二个合并到第一个

        ListNode* h1 = l[begin];
        ListNode* h2 = l[begin + 1];
        auto* h = merge(h1, h2);
        l[begin] = h;
        l[begin + 1] = nullptr;

    } else if (len > 2) {
        int half = begin + len / 2;
        mergeTwo(l, begin, half);
        mergeTwo(l, half, end);
        auto* h = merge(l[begin], l[half]);
        l[begin] = h;
        l[half] = nullptr;
        // TOOD 这里还有一行
    }
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    mergeTwo(lists, 0, lists.size());
    return lists[0];
}

int main() {
    auto* l1 = vectoToList({1, 3});
    auto* l2 = vectoToList({2, 4, 7, 8, 8, 12});
    auto* l3 = vectoToList({1, 4, 5});
    auto* l4 = vectoToList({8, 13, 43});
    std::vector<ListNode*> v{l1, l2, l3, l4};
    mergeKLists(v);
    for (auto& i : v) {
        printList(i);
        printf("\n");
    }
    return 0;
}