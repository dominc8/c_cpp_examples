#include <iostream>
#include <string>
#include <type_traits>


template<typename T>
void foo(T t)
{
    if constexpr(std::is_same_v<T, std::string>) {
        std::cout << "string: " << t << 
                     " size: " << t.size() << '\n';
    } else {
        std::cout << "other type: " << t << '\n';
    }
}
 
int main()
{
    foo(std::string("123"));

    /* Before C++17 it will not compile because int doesn't have .size() method */
    foo(456);

    return 0;
}

