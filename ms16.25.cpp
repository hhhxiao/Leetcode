#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
//test
using namespace std;

class LRUCache {
   public:
    LRUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        auto iter = this->cache.find(key);
        if (iter == cache.end()) {
            return -1;
        }
        auto value = iter->second->second;
        list.erase(iter->second);
        list.insert(list.begin(), {key, value});
        cache[key] = list.begin();
        return value;
    }

    void put(int key, int value) {
        //找到有没有这个键对应的值
        auto iter = this->cache.find(key);
        if (iter == cache.end()) {
            //没有找到就插入
            this->list.insert(list.begin(), {key, value});
            //更新迭代器
            this->cache[key] = list.begin();
            //如果超了就移除最后一个
            if (list.size() > cap) {
                //获取键的值
                auto last = list.back().first;
                list.pop_back();
                //擦除
                cache.erase(last);
            }
        } else {
            //找到了,擦除旧的，并挪动到头部
            list.erase(iter->second);
            this->list.insert(list.begin(), {key, value});
            this->cache[key] = list.begin();
        }
    }

   private:
    std::list<pair<int, int>> list;
    std::unordered_map<int, std::list<pair<int, int>>::iterator> cache;
    int cap;
};

int main() {
    LRUCache c(2);
    c.put(2, 1);
    c.put(2, 2);
    std::cout << c.get(2) << std::endl;
    c.put(1, 1);
    c.put(4, 1);
    std::cout << c.get(2) << std::endl;
}
