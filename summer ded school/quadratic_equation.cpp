#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

const double Eps = 1e-6;


enum Token {
    OK,
    NO_ROOTS = 10,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
    UNKNOWN_AMOUNT,
    ERROR,
    COOL,
    GREATER,
    LESS
};

                                                                                              // писать комменты к функциям
const int valid_input(double *n);                                                             // function that has to check if given number is valid
const int output_fun(int amount_of_roots, double *x1, double *x2);                            // output function
const int quad_solve(const double a, const double b, const double c, double *x1, double *x2); // function that solves quadratic equations
const int compare_doubles(const double num1, const double num2);                              // функция сравнения даблов

int main() {

    printf("Quadratic equation solving\n"
           "Enter coefficients for unknown:\n");

    double a = 0;
    double b = 0;
    double c = 0;

    printf("Enter coef a:\n");
    if (valid_input(&a) == OK)
    {
        printf("Enter coef b:\n");
    }
    if (valid_input(&b) == OK)
    {
        printf("Enter coef c:\n");
    }
    if (valid_input(&c) == OK)
    {
        ;
    }
    


    //if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    //{
    //    printf("Incorrect input try again");
    //}
    //else
    //{
    //    ;
    //}

     
    // проверить что возвращает сканф
    // 43 325 3526edwd

    double x1 = 0;
    double x2 = 0;

    int amount_of_roots = 0;
    amount_of_roots = quad_solve(a, b, c, &x1, &x2);
    
    output_fun(amount_of_roots, &x1, &x2);

    return 0;
}

const int compare_doubles(const double num1, const double num2)
{
    if (fabs(num1 - num2) < Eps)
    {
        return COOL;
    }
    else if (fabs(num1 - num2) > Eps)
    {
        return GREATER;
    }
    else 
    {
        return LESS;
    }
}

const int quad_solve(const double a, const double b, const double c, double *x1, double *x2)
{
    double discriminant = 0;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return INF_ROOTS;
            }

            if (-c / a < 0)
            {
                return NO_ROOTS;
            }

            else if (-c / a > 0)
            {
                *x1 = sqrt(-c / a);
                *x2 = -sqrt(-c / a);
                if (*x1 != *x2) return TWO_ROOTS;
                return ONE_ROOT;
            }
        }

        *x1 = -c / b;
        return ONE_ROOT;
    }

    discriminant = b*b - 4 * a * c;
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);
    if (*x1 != *x2) return TWO_ROOTS;
    return ONE_ROOT;
}


const int valid_input(double *x) 
{
    int flag = 0;
    int ch = 0;
    flag = scanf("%lg", x);
    if (flag == 0)
    {
        return ERROR;
    }
    else if (flag == 1)
    {
        do
        {
            ch = getchar();

        }while(ch != '\n');
    }
    else
    {
        return ERROR;
    }
    return OK;
}


const int output_fun(int amount_of_roots, double *x1, double *x2)
{
    switch (amount_of_roots)
        {
        case NO_ROOTS:
            printf("Given equation has no roots\n");
            break;
        case ONE_ROOT:
            printf("Given equation has 1 root: %lg\n", *x1);
            break;
        case TWO_ROOTS:
            printf("Given equation has 2 roots:\n first root is %lg\n second root is %lg\n", *x1, *x2);
            break;
        case INF_ROOTS:
            printf("Given equation has infinite amount of roots\n");
            break;
        default:
            printf("UNKNOWN AMOUNT OF ROOTS\n");
            return UNKNOWN_AMOUNT;
        }
    return OK;
}