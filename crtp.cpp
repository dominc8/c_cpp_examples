#include <iostream>

#define LOG(str)    std::cout << str << "\n"


/* Base */
template <typename Derived>
struct Base {
  void func() {
    static_cast<Derived *>(this)->func();
  };
};

template <typename T>
void callFunc(Base<T> *ptr)
{
    ptr->func();
}


/* Foo */
struct Foo : Base<Foo> {
  void func();
};

void Foo::func()
{
    LOG("Foo func called");
}


/* Bar */
struct Bar : Base<Bar> {
  void func();
};

void Bar::func()
{
    LOG("Bar func called");
}




int main(void)
{
    Foo foo;
    Bar bar;

    LOG("-------------------CRTP--------------------");
    callFunc(&foo);
    LOG("-------------------------------------------");
    callFunc(&bar);
    LOG("-------------------------------------------");


    return 0;
}

