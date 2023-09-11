#include <concurrencysal.h>
#include <stdio.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>

#include "a.h"

class MyLinkedList {
    struct Node {
        int val{0};
        Node* next{nullptr};
        Node* prev{nullptr};
    };

   public:
    MyLinkedList() {}

    int get(int index) {
        auto* node = this->getNode(index);
        return node ? node->val : -1;
    }

    void addAtHead(int val) {
        if (!head_) {
            head_ = new Node();
            head_->val = val;
            tail_ = head_;
        } else {
            auto* node = new Node();
            node->val = val;
            node->next = head_;
            head_->prev = node;
            head_ = node;
        }
        size_++;
    }

    void addAtTail(int val) {
        if (!tail_) {
            tail_ = new Node();
            tail_->val = val;
            head_ = tail_;
        } else {
            auto* node = new Node();
            node->val = val;
            node->prev = tail_;
            tail_->next = node;
            tail_ = node;
        }
        size_++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->size_) return;
        if (index == this->size_) {
            this->addAtTail(val);
        } else if (index == 0) {
            this->addAtHead(val);
        } else {
            auto* ptr = this->getNode(index);
            assert(ptr);
            auto* node = new Node();
            node->val = val;
            node->prev = ptr->prev;
            node->next = ptr;
            if (ptr->prev) ptr->prev->next = node;
            ptr->prev = node;
            this->size_++;
        }
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->size_) return;
        if (this->size_ == 1) {
            if (index == 0) {
                delete this->head_;
                this->head_ = nullptr;
                this->tail_ = nullptr;
                this->size_ = 0;
            }
        } else {
            if (index == 0) {
                auto* old = head_;
                head_ = head_->next;
                head_->prev = nullptr;
                delete old;
            } else if (index == size_ - 1) {
                auto* old = tail_;
                tail_ = tail_->prev;
                tail_->next = nullptr;
                delete old;
            } else {
                auto* node = this->getNode(index);
                assert(node);
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
            }
            this->size_--;
        }
    }

    void prinf() {
        auto p = head_;

        while (p) {
            printf("%d-> ", p->val);
            p = p->next;
        }
        printf("NULL  (%d)\n", this->size_);
    }

    Node* getNode(int index) {
        if (index < 0 || index >= this->size_) return nullptr;
        auto* p = head_;
        while (index > 0) {
            p = p->next;
            index--;
        }
        return p;
    }

   private:
    Node* head_{nullptr};
    Node* tail_{nullptr};
    int size_{0};
};

int main() {
    MyLinkedList l;
    l.addAtIndex(0, 10);
    l.prinf();
    l.addAtIndex(0, 20);
    l.prinf();
    l.addAtIndex(1, 30);
    l.prinf();

    return 0;
}