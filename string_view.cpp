#include <string>
#include <iostream>

void displayString(std::string_view str)
{
    std::cout << str << "\n";
    str.remove_prefix(7);
    std::cout << str << "\n";
}

int main(void)
{
    displayString("Test string to display");

    /* In stdout you will see:
     * Test string to display
     * ring to display
     */

    return 0;
}

