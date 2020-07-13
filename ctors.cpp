#include <iostream>
#include <cstdint>

#define LOG(str)    std::cout << str << "\n"


class Foo
{
public:
    Foo(int x)
    { 
        LOG("Foo ctor");
        mem = new int;
        *mem = x;
    }

    Foo(const Foo& other)
    {
        LOG("Foo copy ctor");
        mem = new int;
        *mem = *(other.mem);
    }

    Foo(Foo&& other)
    {
        LOG("Foo move ctor");
        mem = other.mem;
        other.mem = nullptr;
    }


    Foo& operator=(const Foo& other)
    {
        LOG("Foo copy assignment");
        delete mem;
        mem = new int;
        *mem = *(other.mem);
        return *this;
    }

    Foo& operator=(Foo&& other)
    {
        LOG("Foo move assignment");
        delete mem;
        mem = other.mem;
        other.mem = nullptr;
        return *this;
    }

    ~Foo()
    {
        if (mem == nullptr)
        {
            LOG("Foo dtor, mem is nullptr");
        }
        else
        {
            std::cout << "Foo dtor, mem at " << mem << " is " << *mem << "\n";
        }
        delete mem;
    }

private:
    int* mem = nullptr;

};



class Bar : public Foo
{
public:
    Bar(int x, char character) : Foo(x)
    { 
        LOG("Bar ctor");
        letter = new char;
        *letter = character;
    }

    Bar(const Bar& other) : Foo(other)
    {
        LOG("Bar copy ctor");
        letter = new char;
        *letter = *(other.letter);
    }

    Bar(Bar&& other) : Foo(std::move(other))
    {
        LOG("Bar move ctor");
        letter = other.letter;
        other.letter = nullptr;
    }


    Bar& operator=(const Bar& other)
    {
        Foo::operator=(other);
        LOG("Bar copy assignment");
        delete letter;
        letter = new char;
        *letter = *(other.letter);
        return *this;
    }

    Bar& operator=(Bar&& other)
    {
        Foo::operator=(std::move(other));
        LOG("Bar move assignment");
        delete letter;
        letter = other.letter;
        other.letter = nullptr;
        return *this;
    }

    ~Bar()
    {
        if (letter == nullptr)
        {
            LOG("Bar dtor, letter is nullptr");
        }
        else
        {
            std::cout << "Bar dtor, letter at " << (int*)letter << " is " << *letter << "\n";
        }
        delete letter;
    }

private:
    char* letter = nullptr;

};


int main(void)
{
    LOG("--------------Constructors---------------");
    {
        Foo f1(1);
        Foo f2(f1);
    }

    LOG("-----------------------------------------");
    {
        Foo f1(2);
        Foo f2(std::move(f1));
    }

    LOG("-----------------------------------------");
    {
        Foo f1(3);
        Foo f2 = f1;
    }

    LOG("-----------------------------------------");
    {
        Foo f1(4);
        Foo f2 = std::move(f1);
    }

    LOG("-----------------------------------------");
    {
        Foo f1(5);
        Foo f2(6);
        f1 = f2;
    }

    LOG("-----------------------------------------");
    {
        Foo f1(7);
        Foo f2(8);
        f1 = std::move(f2);
    }

    LOG("-----------------------------------------");
    {
        Bar b1(1, 'a');
        Bar b2(b1);
    }

    LOG("-----------------------------------------");
    {
        Bar b1(2, 'b');
        Bar b2(std::move(b1));
    }

    LOG("-----------------------------------------");
    {
        Bar b1(3, 'c');
        Bar b2 = b1;
    }

    LOG("-----------------------------------------");
    {
        Bar b1(4, 'd');
        Bar b2 = std::move(b1);
    }

    LOG("-----------------------------------------");
    {
        Bar b1(5, 'e');
        Bar b2(6, 'f');
        b1 = b2;
    }

    LOG("-----------------------------------------");
    {
        Bar b1(7, 'g');
        Bar b2(8, 'h');
        b1 = std::move(b2);
    }

    LOG("-----------------------------------------");
    return 0;
}

