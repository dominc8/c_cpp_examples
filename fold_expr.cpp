#include <iostream>

template<typename... T>
auto sum_args(T... t)
{
    return (... + t);
}
 
int main()
{
    std::cout << sum_args(1, 2L, 3.f, 4.2, 5) << "\n";
    return 0;
}
