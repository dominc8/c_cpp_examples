#include <iostream>
#include <type_traits>

void foo() {}
void bar() noexcept {}
 
int main()
{
    using foo_t = decltype(foo);
    using bar_t = decltype(bar);
    if (std::is_same<foo_t, bar_t>::value)
    {
        /* Before C++17 */
        std::cout << "Functions are the same type\n";
    }
    else
    {
        /* After C++17 */
        std::cout << "Functions are different type\n";
    }
}

