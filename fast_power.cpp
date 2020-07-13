#include <iostream>
#include <cmath>


unsigned long long fast_power_rec(unsigned long long a, unsigned long long b)
{
    if (b > 0)
    {
        if (b & 1) return a * fast_power_rec(a * a, b >> 1);
        else return fast_power_rec(a * a, b >> 1);
    }
    else return 1;
}

unsigned long long fast_power_loop(unsigned long long a, unsigned long long b)
{
    unsigned long long result = 1;
    while (b > 0)
    {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}


int main(void)
{
    std::cout << "------------Fast power----------------\n";
    for (int i = 2; i < 8; ++i)
    {
        for (int j = 2; j < 8; ++j)
        {
            std::cout << i << " ^ " << j << "\n";
            std::cout << "recur: " << fast_power_rec(i, j) << "\n";
            std::cout << "loop: " << fast_power_loop(i, j) << "\n";
            std::cout << "cmath: " << std::pow(i, j) << "\n";
        }
    }
    std::cout << "--------------------------------------\n";

    return 0;
}

