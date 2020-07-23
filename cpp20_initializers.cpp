#include <vector>
#include <iostream>


struct A {
  int x;
  int y;
  int z = 123;
};

int main(void)
{
    /* C-style initializers */
    A a {.x{1}, .z = 2}; // a.x == 1, a.y == 0, a.z == 2

    /* range-based for loop initializers */
    for (std::vector v{1, 2, 3}; auto& e : v)
    {
        std::cout << e << ", ";
    }
    std::cout << "\n";

    return 0;
}

