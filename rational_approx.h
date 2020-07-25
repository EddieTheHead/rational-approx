#ifndef RATIONAL_APPROX_H
#define RATIONAL_APPROX_H

#include <stdbool.h>

typedef struct rational_t
{
    int numrerator;
    int denominator;
}rational_t;

void print_rational( rational_t* rat);
rational_t find_approx(double number);


#endif