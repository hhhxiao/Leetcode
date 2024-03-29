#include <array>
#include <iostream>
#include <map>
#include <ratio>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define COLOR
#ifdef COLOR
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#else
#define KNRM ""
#define KRED ""
#define KGRN ""
#define KYEL ""
#define KBLU ""
#define KMAG ""
#define KCYN ""
#define KWHT ""

#endif
template <typename T, typename... U>
struct DbgDecay;

template <typename T>
struct DbgDecay<T> {
    using type = std::decay_t<T>;
};

template <typename T, size_t N>
struct DbgDecay<T[N]> {
    using type = T[N];
};

template <typename T, typename... U>
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

template <>
struct DbgType<char> {
    static std::string name() { return "char"; }
    static std::string value(char t) { return "'" + std::string(1, t) + "'"; }
};

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

template <typename T, size_t M>
struct DbgType<T[M]> {
    static std::string name() { return DbgType<T>::name() + "[" + std::to_string(M) + "]"; }
    static std::string value(T (&t)[M]) {
        if (M == 0) return "{}";
        T* b = t;
        T* e = t + M;
        std::string s = "{" + DbgType<std::decay_t<decltype(*b)>>::value(*b);
        b++;
        while (b != e) {
            s += " " + DbgType<std::decay_t<decltype(*b)>>::value(*b);
            ++b;
        };

        return s + "}";
    }
};

template <typename T>
struct DbgType<T*> {
    static std::string name() { return DbgType<T>::name() + "*"; }
    static std::string value(T* t) { return "?"; }
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
        s += " " + DbgType<std::decay_t<decltype(*b)>>::value(*b);
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
    static std::string name() {
        return "pair" + DbgType<K>::name() + "," + DbgType<V>::name() + ">";
    }
    static std::string value(const std::pair<K, V>& t) {
        return "{" + DbgType<std::decay_t<K>>::value(t.first) + " -> " +
               DbgType<std::decay_t<V>>::value(t.second) + "}";
    }
};

template <typename K, typename V>
struct DbgType<std::map<K, V>> {
    static std::string name() {
        return "map<" + DbgType<K>::name() + "," + DbgType<V>::name() + ">";
    }
    static std::string value(const std::map<K, V>& t) { return container_to_str(t); }
};

template <typename K, typename V>
struct DbgType<std::unordered_map<K, V>> {
    static std::string name() {
        return "u_map<" + DbgType<K>::name() + "," + DbgType<V>::name() + ">";
    }
    static std::string value(const std::unordered_map<K, V>& t) { return container_to_str(t); }
};
inline void x_print(const std::string& name, const std::string& type, const std::string& value) {
    printf(KCYN "%s" KNRM " = " KWHT "%s" KGRN " (%s)\n" KNRM, name.c_str(), type.c_str(),
           value.c_str());
}

#define dbg(x)                                                  \
    x_print(#x, DbgType<DbgDecay<decltype(x)>::type>::value(x), \
            DbgType<DbgDecay<decltype(x)>::type>::name())
