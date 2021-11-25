struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) return head;
    auto newHead = head->next;
    ListNode *tail = nullptr;
    auto ptr = head;
    while (true) {
        auto first = ptr;
        auto second = ptr->next;
        if (second) {
            ptr->next = second->next;
            second->next = ptr;
            if (tail) {
                tail->next = second;
            }
            tail = first;
        } else {
            tail->next = first;
            break;
        }
    }
    return newHead;
}

int main(int argc, char const *argv[]) { return 0; }
