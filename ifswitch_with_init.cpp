#include <cstdio>

struct Struct
{
    int val;
};

Struct check_struct(int i)
{
    return { i };
}



int main(void)
{
    /* Before C++17 */
    Struct strct = check_struct(0);
    if (0 == strct.val)
    {
        printf("Val is 0\n");
    }


    strct = check_struct(1);
    switch (strct.val)
    {
        case 1:
            printf("Switch case 1\n");
            break;
        default:
            printf("Switch case default\n");
            break;
    }

    /******************************************************/

    /* After C++17 */
    if (Struct strct = check_struct(0); 0 == strct.val)
    {
        printf("Val is 0\n");
    }

    switch (strct = check_struct(1); strct.val)
    {
        case 1:
            printf("Switch case 1\n");
            break;
        default:
            printf("Switch case default\n");
            break;
    }

    return 0;
}

