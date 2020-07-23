#include <iostream>
#include <tuple>

int main(void)
{
    auto x = std::make_tuple(1, 2.5, 'c');
    std::cout << std::get<1>(x) << "\n";

    std::tuple tpl{1, 122.5, 'c'}; /* Before C++17 explicit std::tuple<int, double, char> would have to be used */
    std::cout << std::get<1>(tpl) << "\n";
}

