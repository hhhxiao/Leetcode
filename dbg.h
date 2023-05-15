#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// #define dbg(x) Printer<decltype(x)>::print(x);

template <typename T>
struct DbgType {
    static std::string name() { return "unknown"; }
    static std::string value(const T& t) { return "unknown"; }
};

#define BASE_TYPE(T)                                                \
    template <>                                                     \
    struct DbgType<T> {                                             \
        static std::string name() { return #T; }                    \
        static std::string value(T t) { return std::to_string(t); } \
    };
BASE_TYPE(bool)
BASE_TYPE(char)
BASE_TYPE(short)
BASE_TYPE(int)
BASE_TYPE(long)
BASE_TYPE(long long)
BASE_TYPE(unsigned char)
BASE_TYPE(unsigned short)
BASE_TYPE(unsigned int)
BASE_TYPE(unsigned long)
BASE_TYPE(unsigned long long)
BASE_TYPE(float)
BASE_TYPE(double)
// 字符串
template <>
struct DbgType<std::string> {
    static std::string name() { return "string"; }
    static std::string value(const std::string& t) { return t; }
};

template <>
struct DbgType<const char*> {
    static std::string name() { return "const char*"; }
    static std::string value(const char* t) { return t; }
};

// 容器
template <typename Container, typename Begin = decltype(std::begin(std::declval<Container>()))>
std::string container_to_str(const Container& v) {
    auto b = v.begin();
    auto e = v.end();
    if (b == e) return "{}";

    std::string s = "{" + DbgType<std::decay_t<decltype(*b)>>::value(*b);
    b++;
    while (b != e) {
        s += ", " + DbgType<std::decay_t<decltype(*b)>>::value(*b);
        ++b;
    };

    return s + "}";
}

template <typename T>
struct DbgType<std::vector<T>> {
    static std::string name() { return "vec<" + DbgType<T>::name() + ">"; }
    static std::string value(const std::vector<T>& t) { return container_to_str(t); }
};

template <typename T, size_t N>
struct DbgType<std::array<T, N>> {
    static std::string name() { return DbgType<T>::name() + "[" + std::to_string(N) + "]"; }
    static std::string value(const std::array<T, N>& t) { return container_to_str(t); }
};

template <typename T>
struct DbgType<std::set<T>> {
    static std::string name() { return "set<" + DbgType<T>::name() + ">"; }
    static std::string value(const std::set<T>& t) { return container_to_str(t); }
};

template <typename T>
struct DbgType<std::unordered_set<T>> {
    static std::string name() { return "u_set<" + DbgType<T>::name() + ">"; }
    static std::string value(const std::unordered_set<T>& t) { return container_to_str(t); }
};

// pair & map
template <typename K, typename V>
struct DbgType<std::pair<K, V>> {
    static std::string name() { return "pair" + DbgType<K>::name() + "," + DbgType<V>::name() + ">"; }
    static std::string value(const std::pair<K, V>& t) {
        return "{" + DbgType<std::decay_t<K>>::value(t.first) + " -> " + DbgType<std::decay_t<V>>::value(t.second) +
               "}";
    }
};

template <typename K, typename V>
struct DbgType<std::map<K, V>> {
    static std::string name() { return "map<" + DbgType<K>::name() + "," + DbgType<V>::name() + ">"; }
    static std::string value(const std::map<K, V>& t) { return container_to_str(t); }
};

template <typename K, typename V>
struct DbgType<std::unordered_map<K, V>> {
    static std::string name() { return "u_map<" + DbgType<K>::name() + "," + DbgType<V>::name() + ">"; }
    static std::string value(const std::unordered_map<K, V>& t) { return container_to_str(t); }
};
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

void print(const std::string& name, const std::string& type, const std::string& value) {
    printf(KCYN "%s" KNRM " = " KWHT "%s" KGRN " (%s)\n" KNRM, name.c_str(), type.c_str(), value.c_str());
}

#define dbg(x) print(#x, DbgType<decltype(x)>::value(x), DbgType<decltype(x)>::name())
