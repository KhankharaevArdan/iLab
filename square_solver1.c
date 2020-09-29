
// "Square equation solver"  //


//===================================================================================


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//===================================================================================

const double ACCURACY = 1E-6;
const int INF_ROOTS = -1;
const int NO_ROOTS = 0;
const int NUMBER_OF_TESTS = 10;

//===================================================================================

int linear_solver(double b, double c, double* x1);
int square_solver(double a, double b, double c, double* x1, double* x2);
int is_zero(double value);
void unit_test();
int manual_test();
void switch_nRoots(int nRoots, double x1, double x2);


//===================================================================================


int main()
{
    unit_test();
    manual_test();
}

//===================================================================================


int linear_solver(double b, double c, double* x1)   //������� ������� ��������� ���������
{
    assert(x1 != NULL);
    assert(b  != NAN);
    assert(c  != NAN);

    if ( is_zero(b) && is_zero(c) )
    {
        return INF_ROOTS;
    }

    if ( is_zero(b) && !is_zero(c) )
    {
        return NO_ROOTS;
    }

    if ( !is_zero(b) && is_zero(c) )
    {
        *x1 = 0;
        return 1;
    }

    if ( !is_zero(b) && !is_zero(c) )
    {
        *x1 = -c / b;
        return 1;
    }
}

//===================================================================================


int square_solver(double a, double b, double c, double* x1, double* x2)     // ������� ������� ����������� ���������
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(a  != NAN);
    assert(b  != NAN);
    assert(c  != NAN);

    double discr = b * b - 4 * a * c;

    if (discr < 0)
    {
        return NO_ROOTS;
    }

    if ( is_zero(discr) )
    {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }

    else
    {
        double sqrt_discr = sqrt(discr);
        *x1 = (-b - sqrt_discr) / (2 * a);
        *x2 = (-b + sqrt_discr) / (2 * a);
        assert(x1 != x2);
        return 2;
    }

}

//===================================================================================


int is_zero(double value)   // ������� ��������� � �����
{
    if ( fabs(value) >= ACCURACY )
        return 0;     //if value > 0
        return 1;     //if value == 0
}

//===================================================================================


void unit_test()
{
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    assert(input != NULL);

    output = fopen("output.txt", "w");

    int i = 0;
    int test_failed = 0;

    for(i = 0; i < NUMBER_OF_TESTS; i++)
    {
        double a = NAN, b = NAN, c = NAN, res1 = NAN, res2 = NAN;
        int number_of_roots = NAN;
        fscanf(input, "%lg %lg %lg %d %lg %lg\n", &a, &b, &c, &number_of_roots, &res1, &res2);

      //  if (fscanf(input, "%lg %lg %lg %d %lg %lg\n", &a, &b, &c, &number_of_roots, &res1, &res2) != 6)
      //      printf("ERROR IN FILE\n");

        int nRoots = 0;
        double x1 = 0, x2 = 0;

        if ( !is_zero(a) )
            nRoots = square_solver(a, b, c, &x1, &x2);
        else
            nRoots = linear_solver(b, c, &x1);

        switch_nRoots(nRoots, x1, x2);

        if (number_of_roots == nRoots)
        {
            if (nRoots == INF_ROOTS)
                fprintf(output, "YES\n");

            if (nRoots == 1)
            {
                if (x1 - res1 < ACCURACY)
                    fprintf(output, "YES\n");
                else
                {
                    fprintf(output, "NO\n");
                    test_failed = test_failed + 1;
                }
            }

            if (nRoots == 2)
            {
                if ( (x1 - res1 < ACCURACY) && (x2 - res2 < ACCURACY) )
                    fprintf(output, "YES\n");
                else
                {
                    fprintf(output, "NO\n");
                    test_failed = test_failed + 1;
                }
            }

            if (nRoots = NO_ROOTS)
                fprintf(output, "YES\n");
        }

        else
        {
            fprintf(output, "NO\n");
            test_failed = test_failed + 1;
        }
    }

    if (test_failed == 0)
        printf("ALL TESTS ARE DONE\n");
    else
        printf("TESTS FAILED: %d", test_failed);

    fclose(input);
    fclose(output);
}

//===================================================================================


int manual_test()
{
    double a = NAN, b = NAN, c = NAN;
    printf("\n"
           "Square equation solver\n"
           "Enter 3 coefficients of squad equation a, b, c:\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("ERROR\n");
        return 0;
    }
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);

    double x1 = NAN, x2 = NAN;
    int nRoots = 0;

    if (!is_zero(a))
        nRoots = square_solver(a, b, c, &x1, &x2);
    else
        nRoots = linear_solver(b, c, &x1);
    switch_nRoots(nRoots, x1, x2);
}

//===================================================================================
void switch_nRoots(int nRoots, double x1, double x2)
{
    switch (nRoots)
    {
        case 0:         printf("No roots!\n");
                        break;

        case 1:         printf("1 root: x = %lg\n", x1);
                        break;

        case 2:         printf("2 roots: x1 = %lg, x2 = %lg\n", x1, x2);
                        break;

        case INF_ROOTS: printf("INFTY ROOTS\n");
                        break;

        default:        printf("ERROR");
                        break;
    }
}