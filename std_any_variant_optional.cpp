#include <string>
#include <iostream>
#include <tuple>
#include <any>
#include <optional>
#include <variant>

struct visitor
{
    void operator()(int& val) const {
        std::cout << "std::visit int: " << val << '\n';
    }
 
    template<typename T> void operator()(T&& t) const {
        std::cout << "std::visit templated: " << t << '\n';
    }
};


std::optional<int> get_optional(int i)
{
    if (i == 0)
    {
        return {};
    }
    else
    {
        return 100;
    }
}


int main()
{
    /* std::any */
    std::any foo_any;
    foo_any = 420;
    std::cout << std::any_cast<int>(foo_any) << "\n";
    foo_any = std::string("string_in_any");
    std::cout << std::any_cast<std::string>(foo_any) << "\n";

    try
    {
        std::cout << std::any_cast<float>(foo_any) << "\n";
    }
    catch (const std::bad_any_cast &e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    

    /* std::optional */
    auto foo_opt = get_optional(1);
    if(foo_opt) /* foo_opt.has_value()*/
    {
        std::cout << foo_opt.value() << "\n";
    }

    foo_opt = get_optional(0);
    std::cout << foo_opt.value_or(123) << "\n"; /* if foo_opt is empty it will return 123 */


    /* std::variant */
    std::variant<int, std::string, double> foo_var = std::string("string_in_variant");
    if (std::holds_alternative<std::string>(foo_var))
    {
        std::cout << "string: " <<  std::get<std::string>(foo_var) << "\n"; 
    }

    foo_var = 23.1;
    if (std::holds_alternative<int>(foo_var))
    {
        std::cout << "int: " <<  std::get<int>(foo_var) << "\n"; 
    }
    else if (std::holds_alternative<double>(foo_var))
    {
        std::cout << "double: " <<  std::get<double>(foo_var) << "\n"; 
    }

 
    /* std::variant with std::visit */
    foo_var = std::string("string_in_variant");
    std::visit(visitor{}, foo_var);
 
    foo_var = 4.76;
    std::visit(visitor{}, foo_var);
 
    foo_var = 213;
    std::visit(visitor{}, foo_var);


}
