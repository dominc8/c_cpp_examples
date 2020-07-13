#include <iostream>

#define LOG(str)    std::cout << str << "\n"

template <typename T>
void print_val(T x) { std::cout << "templated type: " << x; }

void print_val(float x) { std::cout << "float: " << x; }


template <typename T>
class Foo
{
public:
    Foo(): m_x(0) { LOG("Foo created without x"); }
    Foo(T x): m_x(x) { std::cout << "Foo created with " << x << "\n"; }
    ~Foo() { std::cout << "Foo with "; print_val(m_x); std::cout << " destroyed\n"; }

private:
    T m_x;
};



template <typename T>
class Bar: public Foo<T>
{
public:
    Bar() { LOG("Bar created without x"); }
    Bar(T x): Foo<T>(x) { std::cout << "Bar created with " << x << "\n"; }
    ~Bar() { LOG("Bar destroyed"); }
};



int main(void)
{
    LOG("--------------------Templates---------------------");
    {
        LOG("Go into scope");
        Foo<int> foo_i(420);
        Foo<float> foo_f(3.14f);
        LOG("Go out of scope");
    }

    LOG("--------------------------------------------------");
    {
        LOG("Go into scope");
        Bar<int> bar_v;
        Bar<int> bar_i(2);
        Bar<float> bar_f(2.34f);
        LOG("Go out of scope");
    }

    LOG("--------------------------------------------------");
    return 0;
}

