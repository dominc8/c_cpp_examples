#include <cstdio>
#include <string>
#include <tuple>


typedef int int_array3[3];
int_array3 example_array = {4, 2, 0};

struct Struct
{
    float f1;
    std::string str;
    int d2;
};


int_array3& return_array(void)
{
    return example_array;
}


Struct return_struct(void)
{
    return {1.5f, "Test string", 23 };
}

std::tuple<double, char, std::string> return_tuple(void)
{
    return std::make_tuple(10.12, 'A', "tuple string");
}

int main(void)
{
    /* Before C++17 */
    int_array3& arr = return_array();
    printf("arr: %d, %d, %d\n", arr[0], arr[1], arr[2]);

    Struct strct = return_struct();
    printf("strct: {%f, %s, %d}\n", strct.f1, strct.str.c_str(), strct.d2);

    auto tpl = return_tuple();
    printf("tpl: <%lf, %c, %s>\n\n\n", std::get<0>(tpl), std::get<1>(tpl), std::get<2>(tpl).c_str());

    /***********************************************************************/

    /* After C++17 */
    auto [a, b, c] = return_array();
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    auto [f, str, d] = return_struct();
    printf("Values in returned struct: {%f, %s, %d}\n", f, str.c_str(), d);

    auto [tpl_d, tpl_c, tpl_s] = return_tuple();
    printf("Values in returned tuple: <%lf, %c, %s>\n", tpl_d, tpl_c, tpl_s.c_str());

    return 0;
}
    
