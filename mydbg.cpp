#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define dbg(x) Printer<decltype(x)>::print(x);

template <typename... T>
struct TypeName {
    static std::string name() { return "unknown"; }
};

#define SIMPLE_TYPE(T)                           \
    template <>                                  \
    struct TypeName<T> {                         \
        static std::string name() { return #T; } \
    };

SIMPLE_TYPE(char)
SIMPLE_TYPE(short)
SIMPLE_TYPE(int)
SIMPLE_TYPE(long)
SIMPLE_TYPE(long long)
SIMPLE_TYPE(unsigned char)
SIMPLE_TYPE(unsigned short)
SIMPLE_TYPE(unsigned int)
SIMPLE_TYPE(unsigned long)
SIMPLE_TYPE(unsigned long long)
SIMPLE_TYPE(float)
SIMPLE_TYPE(double)

template <typename T>
struct TypeName<std::vector<T>> {
    static std::string name() { return "vec<" + TypeName<T>::name() + ">"; }
};

template <typename T, typename U>
struct TypeName<std::map<T, U>> {
    static std::string name() { return "map<" + TypeName<T>::name() + "," + TypeName<U>::name() + ">"; }
};

template <typename T, typename U>
struct TypeName<std::unordered_map<T, U>> {
    static std::string name() { return "u_map<" + TypeName<T>::name() + "," + TypeName<U>::name() + ">"; }
};

template <typename T>
struct TypeName<std::unordered_set<T>> {
    static std::string name() { return "u_set<" + TypeName<T>::name() + ">"; }
};

template <typename T>
struct TypeName<std::set<T>> {
    static std::string name() { return "set<" + TypeName<T>::name() + ">"; }
};

template <typename T>
struct TypeValue {
    static std::string value(const T& t) { return "unknown"; }
};

template <>
struct TypeValue<int> {
    static std::string value(int t) { return std::to_string(t); }
};

template <typename T>
struct TypeValue<std::vector<T>> {
    static std::string value(const std::vector<T>& t) {
        std::string s = "";
        for (auto& v : t) {
            s += TypeValue<T>::value(v) + " ";
        }
        return s;
    }
};

#define TYPE(x) TypeName<decltype(x)>::name().c_str()

int main() {
    std::vector<int> v{1, 2, 3, 4};
    printf("%s", TypeValue<decltype(v)>::value(v).c_str());
    return 0;
}