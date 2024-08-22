#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

const double Eps = 1e-6;


enum CONDITION {
    OK,
    ERROR,
};

enum COMPARE {
    EQUAL = 2,
    GREATER,
    LESS
};

enum ROOTS {
    NO_ROOTS = 10,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
    UNKNOWN_AMOUNT,
};

                                                                                              // писать комменты к функциям
const CONDITION valid_input(double *n);                                                       // function that has to check if given number is valid
const int output_fun(const int amount_of_roots, double *x1, double *x2);                      // output function
const int quad_solve(const double a, const double b, const double c, double *x1, double *x2); // function that solves quadratic equations
const int compare_doubles(const double num1, const double num2);                              // функция сравнения даблов
const double get_value(const double *num);                                                    // функция запроса вывода аргумента
const CONDITION input_function(double *a, double *b, double *c);                              // функция ввода коэффициентов


int main() {

    printf("Quadratic equation solving\n"
           "Enter coefficients for unknown:\n");

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    int amount_of_roots = 0;

    input_function(&a, &b, &c);
    amount_of_roots = quad_solve(a, b, c, &x1, &x2); 
    output_fun(amount_of_roots, &x1, &x2);

    return 0;
}
// сделать структуру

const int compare_doubles(const double num1, const double num2)
{
    if (fabs(num1 - num2) < 2 * Eps)
    {
        return EQUAL;
    }
    else if (num1 - num2 > Eps)
    {
        return GREATER;
    }
    else if (num1 - num2 < -Eps) 
    {
        return LESS;
    }
    return ERROR;
}

const int quad_solve(const double a, const double b, const double c, double *x1, double *x2)
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    double discriminant = 0;
    // линейный случай в отдельную функцию
    if (compare_doubles(a, 0.0) == EQUAL)
    {
        if (compare_doubles(b, 0.0) == EQUAL)
        {
            if (compare_doubles(c, 0.0) == EQUAL)
            {
                return INF_ROOTS;
            }

            if (compare_doubles(-c / a, 0.0) == LESS)
            {
                return NO_ROOTS;
            }

            else if (compare_doubles(-c / a, 0.0) == GREATER)
            {
                *x1 = sqrt(-c / a);
                *x2 = -sqrt(-c / a);

                if (compare_doubles(*x1, *x2) != EQUAL) return TWO_ROOTS;
                return ONE_ROOT;
            }
        }

        *x1 = -c / b;
        return ONE_ROOT;
    }

    discriminant = b*b - 4 * a * c;
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);

    if (compare_doubles(*x1, *x2) != EQUAL) return TWO_ROOTS;
    return ONE_ROOT;
}


const CONDITION valid_input(double *x) 
{
    assert(x != nullptr);

    int flag = 0;
    int ch   = 0;
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
            if (isspace(ch) == 0)
            {
                return ERROR;
            }

        }while(ch != '\n' && ch != EOF);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

const CONDITION input_function(double *a, double *b, double *c)
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    printf("Enter coef a:\n");
    if (valid_input(a) == OK)
    {
        printf("Enter coef b:\n");
    }
    else if (valid_input(a) == ERROR)
    {
        printf("INCORRECT INPUT\n");
    }
    if (valid_input(b) == OK)
    {
        printf("Enter coef c:\n");
    }
    else if (valid_input(b) == ERROR)
    {
        printf("INCORRECT INPUT\n");
    }
    if (valid_input(c) == OK)
    {
        ;
    }
    else if (valid_input(c) == ERROR)
    {
        printf("INCORRECT INPUT\n");
    }
    
    return OK;
}


const int output_fun(const int amount_of_roots, double *x1, double *x2)
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);

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

const double get_value(const double *num) // learn inline functions
{
    assert(num != nullptr);

    return *num;
}