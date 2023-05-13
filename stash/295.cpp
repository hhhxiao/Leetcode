#include <iostream>
#include <queue>

class MedianFinder {
   public:
    std::priority_queue<int> min_part_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> max_part_;

   public:
    MedianFinder() {}
    void addNum(int num) {
        if (min_part_.size() == max_part_.size()) {
            max_part_.push(num);
            min_part_.push(max_part_.top());
            max_part_.pop();

        } else {
            min_part_.push(num);
            max_part_.push(min_part_.top());
            min_part_.pop();
        }
    }
    double findMedian() {
        if (min_part_.size() == max_part_.size())
            return (min_part_.top() + max_part_.top()) / 2.0;
        return min_part_.top();
    }
};

int main() {
    MedianFinder f;
    f.max_part_.push(1);
    f.max_part_.push(1);
    f.max_part_.push(1);
    f.max_part_.push(2);

    while (!f.max_part_.empty()) {
        std::cout << f.max_part_.top();
        f.max_part_.pop();
    }

    return 0;
}
