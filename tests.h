
#include "is_zero.h"
#include "switch_nRoots.h"
#include "linear_solver.h"
#include "square_solver.h"
//===================================================================================

const int NUMBER_OF_TESTS = 10; ///< Number of tests in unit test

//===================================================================================

/*!
    \brief manual test
    \param[in] a coefficient of quadratic equation
    \param[in] b coefficient of quadratic equation
    \param[in] c coefficient of quadratic equation

    \code
    int manual_test()
    {
        double a = NAN, b = NAN, c = NAN;
        printf("\n"
               "Square equation solver\n"
               "Enter 3 coefficients of squad equation a, b, c:\n");
        scanf("%lg %lg %lg", &a, &b, &c);

        if(scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
            printf("ERROR\n");
            return 0;
        }
        assert(a != NAN);
        assert(b != NAN);
        assert(c != NAN);

        double x1 = NAN, x2 = NAN;
        int nRoots = 0;

        if(!is_zero(a))
            nRoots = square_solver(a, b, c, &x1, &x2);
        else
            nRoots = linear_solver(b, c, &x1);
        switch_nRoots(nRoots, x1, x2);
    return 0;
    }
    \endcode
*/

int manual_test();

/*!
    \brief Unit test
    \param[in] a coefficient of quadratic equation
    \param[in] b coefficient of quadratic equation
    \param[in] c coefficient of quadratic equation
    \pdram[in] number_of_roots right number of solutions of quadratic equation
    \param[in] res1 right solution of quadratic equation
    \param[in] res2 right solution of quadratic equation
    \param[out] x1 solution of quadratic equation
    \param[out] x2 solution of quadratic equation
    \param[out] test_failed number of failed tests
    \param[out] nRoots number of solutions of quadratic equation
    \code
    {
        FILE* input = fopen("input.txt", "r");
        FILE* output = fopen("output.txt", "w");
        assert(input != NULL);
        int i = 0;
        int test_failed = 0;
        for(i = 0; i < NUMBER_OF_TESTS; i++)
        {
            double a = NAN, b = NAN, c = NAN, res1 = NAN, res2 = NAN;
            int number_of_roots = NAN;
            fscanf(input, "%lg %lg %lg %d %lg %lg\n", &a, &b, &c, &number_of_roots, &res1, &res2);
            int nRoots = 0;
            double x1 = 0, x2 = 0;
            if(!is_zero(a))
                nRoots = square_solver(a, b, c, &x1, &x2);
            else
                nRoots = linear_solver(b, c, &x1);
            switch_nRoots(nRoots, x1, x2);
            if(number_of_roots == nRoots)
            {
                if(nRoots == INF_ROOTS)
                    fprintf(output, "YES\n");
                if(nRoots == 1)
                {
                    if(is_zero(x1 - res1))
                        fprintf(output, "YES\n");
                    else
                    {
                        fprintf(output, "TEST %d FAILED\n", i + 1);
                        test_failed = test_failed + 1;
                    }
                }
                if(nRoots == 2)
                {
                    if((is_zero(x1 - res1)) && (is_zero(x2 - res2)))
                        fprintf(output, "YES\n");
                    else
                    {
                        fprintf(output, "TEST %d FAILED\n", i + 1);
                        test_failed = test_failed + 1;
                    }
                }
                if(nRoots == NO_ROOTS)
                    fprintf(output, "YES\n");
            }
            else
            {
                fprintf(output, "TEST %d FAILED\n", i + 1);
                test_failed = test_failed + 1;
            }
        }
        if(test_failed == 0)
            printf("ALL TESTS ARE DONE\n");
        else
            printf("TESTS FAILED: %d", test_failed);
        fclose(input);
        fclose(output);
    }
    \endcode
*/

void unit_test();

//===================================================================================

int manual_test()
{
    double a = NAN, b = NAN, c = NAN;
    printf("\n"
           "Square equation solver\n"
           "Enter 3 coefficients of squad equation a, b, c:\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    if(scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("ERROR\n");
        return 0;
    }
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);

    double x1 = NAN, x2 = NAN;
    int nRoots = 0;

    if(!is_zero(a))
        nRoots = square_solver(a, b, c, &x1, &x2);
    else
        nRoots = linear_solver(b, c, &x1);
    switch_nRoots(nRoots, x1, x2);
return 0;
}

//===================================================================================

void unit_test()
{
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    assert(input != NULL);

    int i = 0;
    int test_failed = 0;

    for(i = 0; i < NUMBER_OF_TESTS; i++)
    {
        double a = NAN, b = NAN, c = NAN, res1 = NAN, res2 = NAN;
        int number_of_roots = NAN;
        fscanf(input, "%lg %lg %lg %d %lg %lg\n", &a, &b, &c, &number_of_roots, &res1, &res2);

        int nRoots = 0;
        double x1 = 0, x2 = 0;

        if(!is_zero(a))
            nRoots = square_solver(a, b, c, &x1, &x2);
        else
            nRoots = linear_solver(b, c, &x1);

        switch_nRoots(nRoots, x1, x2);

        if(number_of_roots == nRoots)
        {
            if(nRoots == INF_ROOTS)
                fprintf(output, "YES\n");
            if(nRoots == 1)
            {
                if(is_zero(x1 - res1))
                    fprintf(output, "YES\n");
                else
                {
                    fprintf(output, "TEST %d FAILED\n", i + 1);
                    test_failed = test_failed + 1;
                }
            }
            if(nRoots == 2)
            {
                if((is_zero(x1 - res1)) && (is_zero(x2 - res2)))
                    fprintf(output, "YES\n");
                else
                {
                    fprintf(output, "TEST %d FAILED\n", i + 1);
                    test_failed = test_failed + 1;
                }
            }
            if(nRoots == NO_ROOTS)
                fprintf(output, "YES\n");
        }
        else
        {
            fprintf(output, "TEST %d FAILED\n", i + 1);
            test_failed = test_failed + 1;
        }
    }
    if(test_failed == 0)
        printf("ALL TESTS ARE DONE\n");
    else
        printf("TESTS FAILED: %d", test_failed);

    fclose(input);
    fclose(output);
}








