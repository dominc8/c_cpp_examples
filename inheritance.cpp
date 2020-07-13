#include <iostream>
#include <string>

class Foo
{
public:
    Foo(const std::string& name) : name(name)
    {
    }
    virtual void printName() const { std::cout << name << "\n"; }
private:
    std::string name;
};


class Bar : private Foo
{
public:
    Bar() : Foo("Bar")
    {
    }
    using Foo::Foo;
    void callPrintName() { printName();}
    // void printName() const {}  /* I can override it but normally cannot call it from outside because by default it is private */
};


void polyPrintName(const Foo *foo)
{
    foo->printName();
}


int main(void)
{
    std::cout << "------------Private inheritance-------------\n";
    Foo f("Foo name");
    Bar b;
    Bar b2("Custom bar name");

    f.printName();
    // b.printName();       /* This is private */
    b.callPrintName();

    polyPrintName(&f);
    // polyPrintName(&b);   /* Foo is an inaccessible base from Bar */
    b2.callPrintName();
    std::cout << "--------------------------------------------\n";

    return 0;
}

