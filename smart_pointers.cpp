#include <memory>
#include <iostream>

#define LOG(str)    std::cout << str << "\n"


int g_int = (66 << 8) + 65;

class Foo
{
public:
    Foo() { LOG("Foo created"); }
    Foo(int i): Foo() { m_i = i; std::cout << "Passed " << i << "\n"; }
    ~Foo() { LOG("Foo destroyed"); }
    void Print() { std::cout << "Foo has " << m_i << "\n"; }
private:
    int m_i;
};


void get_Foo(std::shared_ptr<Foo>& foo)
{
    LOG("Go into function get_Foo scope");
    auto ptr = std::make_shared<Foo>(10);
    foo = ptr;
    LOG("Go out of function get_Foo scope");
}


std::unique_ptr<Foo> get_unique_Foo()
{
    LOG("Go into function get_uniq scope");
    std::unique_ptr<Foo> ret_ptr = std::make_unique<Foo>(420);
    LOG("Go out of function get_uniq scope");
    return ret_ptr;
}


void do_sth_with_unique_ptr(std::unique_ptr<Foo> foo_ptr)
{
    LOG("Go into function do_sth scope");
    foo_ptr->Print();
    LOG("Go out of function do_sth scope");
}



int main(void)
{
    LOG("----------------Smart pointers--------------------");

    char* c_ptr = (char *)&g_int;
    int* i_ptr = &g_int;
    std::cout << "sizeof(c_ptr) " << sizeof(c_ptr) << ", sizeof(*c_ptr) " << sizeof(*c_ptr) << ", val " << *c_ptr << "\n";
    std::cout << "sizeof(i_ptr) " << sizeof(i_ptr) << ", sizeof(*i_ptr) " << sizeof(*i_ptr) << ", val " << *i_ptr << "\n";

    ++c_ptr;
    std::cout << "sizeof(c_ptr) " << sizeof(c_ptr) << ", sizeof(*c_ptr) " << sizeof(*c_ptr) << ", val " << *c_ptr << "\n";

    int arr[20];
    std::cout << "sizeof(arr) " << sizeof(arr) << ", sizeof(*arr) " << sizeof(*arr) << "\n";

    LOG("--------------------------------------------------");
    {
        LOG("Go into scope");
        auto ptr = std::make_unique<Foo>();
        auto ptr2 = std::make_unique<Foo>(2);
        std::cout << "sizeof(ptr) " << sizeof(ptr) << "\n";
        LOG("Go out of scope");
    }

    LOG("--------------------------------------------------");
    {
        LOG("Go into scope");
        std::shared_ptr<Foo> foo_ptr;
        get_Foo(foo_ptr);
        foo_ptr->Print();
        LOG("Go out of scope");
    }

    LOG("--------------------------------------------------");
    {
        LOG("Go into scope");
        auto foo_ptr = get_unique_Foo();
        foo_ptr->Print();
        do_sth_with_unique_ptr(std::move(foo_ptr));
        LOG("Go out of scope");
    }

    LOG("--------------------------------------------------");
    return 0;
}

