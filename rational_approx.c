#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "rational_approx.h"

static rational_t farey_add(rational_t* a, rational_t* b);
static double rational_to_double( rational_t* rat);
static bool farey_iter(double number, rational_t* high, rational_t* low, double *error);


/* returns true if exact number is found */
static bool farey_iter(double number, rational_t* high, rational_t* low, double *error)
{
    rational_t naive_sum;
    rational_t old;
    double approx;
    if(error != NULL)
    {
        error = 0;
    } 

    approx = rational_to_double(high);
    if(approx == number) 
    {
        *high = *high;
        *low = *high;
        return true;
    }
    approx = rational_to_double(low);
    if(approx == number) 
    {
        *high = *low;
        *low = *low;
        return true;
    }

    /* farey sum is guaranteed to be between a and b */ 
    naive_sum = farey_add( high, low);
    approx = rational_to_double(&naive_sum);
    // printf("approx: %f, number: %f\n", approx, number);
    if(approx == number) 
    {
        *high = naive_sum;
        *low = naive_sum;
        return true;
    }
    else if(approx < number)
    {
        *low = naive_sum; 
    }
    else
    {
        *high = naive_sum;
    }
    if(error != NULL)
    {
        *error = sqrt((approx - number)*(approx - number));
    }

    return false;    
}

rational_t find_approx(double number)
{
    rational_t result = { 0, 0};
    rational_t high = {1, 1};
    rational_t low = {0, 1};
    const int max_interations = 10000;

    double error = 0;
    double rem = 0;
    int quotient = floor(number); 
    bool found = false;

    if(quotient != 0)
    {
        rem = remainder(number, quotient);
    } else rem = number;
    
    for(int i = 0; i < max_interations; ++i)
    {
        
        found = farey_iter(rem, &high, &low, &error);
        // printf("step: %d, error: %f\n", i, error);
        // printf("high");
        // print_rational(&high);
        // printf("low");
        // print_rational(&low);

        if(found) break;
    }

    high.numrerator = high.numrerator + quotient * high.denominator;
    result = high;

    return result;
}



static double rational_to_double( rational_t* rat)
{
    return ((double) rat->numrerator) / ((double) rat->denominator);
}


static rational_t farey_add(rational_t *a, rational_t *b)
{
    rational_t result;
    result.numrerator = a->numrerator + b->numrerator;
    result.denominator = a->denominator + b->denominator;
    return result;
}


void print_rational( rational_t* rat)
{
    int num_len = (int) log10(abs(rat->numrerator)) + 1;
    int den_len = (int) log10(abs(rat->denominator)) + 1;
    
    if(rat->numrerator < 0) num_len++;
    if(rat->denominator < 0) den_len++;

    int max_len = (num_len > den_len) ? num_len : den_len;
    printf("\n");

    int spaces = ceil((max_len - num_len) / 2.0);  
    for(int i = 0; i < spaces; ++i )
    {
        printf(" ");
    }
    printf("%d\n", rat->numrerator);

    for(int i = 0; i < max_len; ++i )
    {
        printf("-");
    }
    printf("\n");

    spaces = (max_len - den_len) / 2;  
    for(int i = 0; i < spaces; ++i )
    {
        printf(" ");
    }
    printf("%d\n", rat->denominator);
}
