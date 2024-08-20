#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


const int SS_INF_ROOTS = 3;


int quad_solve(double a, double b, double c, double *x1, double *x2);
void valid_input(double *n);


int main() {

    printf("Qadratic equation solving\n"
           "Enter coefficients for unknown:\n");

    double a = 0;
    double b = 0;
    double c = 0;

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("Incorrect input try again");
    }
    else
    {
        ;
    }

    //valid_input(&a);
    //valid_input(&b);
    //valid_input(&c);

    // проверить что возвращает сканф
    
    
    // 43 325 3526edwd
    double x1 = 0;
    double x2 = 0;

    int amount_of_roots = 0;
    amount_of_roots = quad_solve(a, b, c, &x1, &x2);
    
    switch (amount_of_roots)
    {
    case 0:
        printf("Given equation has no roots\n");
        break;
    case 1:
        printf("Given equation has 1 root: %lg\n", x1);
        break;
    case 2:
        printf("Given equation has 2 roots:\n first root is %lg\n second root is %lg\n", x1, x2);
        break;
    case SS_INF_ROOTS:
        printf("Given equation has infinite amount of roots\n");
        break;
    default:
        printf("UNKNOWN AMOUNT OF ROOTS\n");
        return 1;
    }

// enum
    return 0;
}


int quad_solve(double a, double b, double c, double *x1, double *x2)
{
    double discriminant = 0;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return 3;
            }

            if (-c / a < 0)
            {
                return 0;
            }

            else if (-c / a > 0)
            {
                *x1 = sqrt(-c / a);
                *x2 = -sqrt(-c / a);
                if (*x1 != *x2) return 2;
                return 1;
            }
        }

        *x1 = -c / b;
        return 1;
    }

    discriminant = b*b - 4 * a * c;
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);
    if (*x1 != *x2) return 2;
    return 1;
}
// писать комменты к функциям

void valid_input(double *n) 
{
    for (*n; (*n = getchar()) != EOF;)
    {
        if (isdigit(*n) == 0) 
        {
            printf("Incorrect input, try again\n");            
        }
    }
}