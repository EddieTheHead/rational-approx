#include "rational_approx.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    rational_t result;

    result = find_approx(0.5);
    printf( "%f = ", 0.5);
    print_rational(&result);
    printf("\n");

    result = find_approx(1.3);
    printf( "%f = ", 1.3);
    print_rational(&result);
    printf("\n");

    result = find_approx(0.0005);
    printf( "%f = ", 0.0005);
    print_rational(&result);
    printf("\n");

    result = find_approx(123.345);
    printf( "%f = ", 123.345);
    print_rational(&result);
    printf("\n");

    result = find_approx(1000.1);
    printf( "%f = ", 1000.1);
    print_rational(&result);
    printf("\n");

    result = find_approx(-1.1);
    printf( "%f = ", -1.1);
    print_rational(&result);
    printf("\n");

    return 0;
}