#include <iostream>

#define LOG(str)    std::cout << str << "\n"

constexpr unsigned int fibonacci(unsigned int x)
{
    if (x == 0 || x == 1) return 1;
    else return (fibonacci(x-2) + fibonacci(x-1));
}

template <typename T, std::size_t N>
class constexpr_array 
{
private:
    constexpr static std::size_t size = N;
    T arr[N] {};
public:
    constexpr T& operator[](std::size_t n)
    {
        if (n < N) return arr[n];
        else throw("Index out of bound");
        
    }
    constexpr const T& operator[](std::size_t n) const
    {
        if (n < N) return arr[n];
        else throw("Index out of bound");
    }
    constexpr const T* begin() const
    {
        return &arr[0];
    }
    constexpr const T* end() const
    {
        return &arr[N];
    }
};

template <typename T, std::size_t N>
constexpr auto generate_fibonacci() -> constexpr_array<T,N>
{
    constexpr_array<T, N> arr;
    for (T i = 0; i < N; ++i)
    {
        arr[i] = fibonacci(i);
    }
    return arr;
}


int main(void)
{
    LOG("-----Constexpr Fibonacci Generator-----");
    constexpr auto fibonacci_arr = generate_fibonacci<unsigned int, 20>();
    for (auto i : fibonacci_arr)
    {
        LOG(i);
    }
    LOG("---------------------------------------");

    return 0;
}

