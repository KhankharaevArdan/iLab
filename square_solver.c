
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
int unit_test();
int manual_test();


//===================================================================================


int main()
        {
        unit_test();

        manual_test();
        }

//===================================================================================


int linear_solver(double b, double c, double* x1)
        {
        assert(x1 != NULL);
        assert(b  != NAN);
        assert(c  != NAN);

        if ((is_zero(b) == 0) && (is_zero(c) == 0))
            {
            return INF_ROOTS;
            }

        if ((is_zero(b) == 0) && (is_zero(c) == 1))
            {
            return 0;
            }

        if ((is_zero(b) == 1) && (is_zero(c) == 0))
            {
            *x1 = 0;
            return 1;
            }

        if ((is_zero(b) == 1) && (is_zero(c) == 1))
            {
            *x1 = -c/b;
            return 1;
            }
        return 3;
        }

//===================================================================================


int square_solver(double a, double b, double c, double* x1, double* x2)
        {
        assert(x1 != NULL);
        assert(x2 != NULL);
        assert(a  != NAN);
        assert(b  != NAN);
        assert(c  != NAN);

        double discr = b *b - 4 *a *c;

            if (discr < 0)
                {
                return 0;
                }

            if (is_zero(discr) == 0)
                {
                *x1 = *x2 = -b /(2 *a);
                return 1;
                }

            else
                {
                double sqrt_discr = sqrt(discr);
                *x1 = (-b - sqrt_discr) /(2 *a);
                *x2 = (-b + sqrt_discr) /(2 *a);
                return 2;
                }
        }

//===================================================================================


int is_zero(double value)
        {
        if (fabs(value) >= ACCURACY)
            return 1;     //if value > 0
            return 0;     //if value == 0
        }

//===================================================================================


int unit_test()
        {
        FILE* input;
        FILE* output;

        input = fopen("input.txt", "r");

        if (input == NULL)
			{
				fprintf(stderr, "This file is empty!");
				return 1;
			}

        output = fopen("output.txt", "w");

        int i = 0;
        int test_failed = 0;

        for(i = 0; i < NUMBER_OF_TESTS; i++)
                {
                double a = NAN, b = NAN, c = NAN;
                int number_of_test = 0;
                fscanf(input, "%lg %lg %lg\n", &a, &b, &c);

                assert(a != NAN);
                assert(b != NAN);
                assert(c != NAN);

                int nRoots = 0;
                double x1 = 0, x2 = 0;

                if (is_zero(a) == 1)


                    nRoots = square_solver(a, b, c, &x1, &x2);


                if (is_zero(a) == 0)

                    nRoots = linear_solver(b, c, &x1);



                        switch (nRoots) {

                        case 0: {
                            fprintf(output, "No roots!\t");
                            break;
                            }

                        case 1: {
                            fprintf(output, "1 root: x = %lg\t", x1);
                            break;
                            }

                        case 2: {
                            fprintf(output, "2 roots: x1 = %lg, x2 = %lg\t", x1, x2);
                            break;
                            }

                        case INF_ROOTS: {
                            fprintf(output, "INFTY ROOTS\t");
                            break;
                            }

                        default: fprintf(output, "ERROR\n");

                        return 0;
                        }

                                switch (number_of_test = i + 1) {

                                    case 1: {
                                        if ((nRoots == 1) && (x1 + 0.25 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 2: {
                                        if (nRoots == INF_ROOTS)
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 3: {
                                        if ((nRoots == 1) && (x1 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 4: {
                                        if (nRoots == NO_ROOTS)
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 5: {
                                        if (nRoots == NO_ROOTS)
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 6: {
                                        if ((nRoots == 2) && (x1 + 1 < ACCURACY) && (x2 + 0.5 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 7: {
                                        if ((nRoots == 1) && (x2 + 1 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 8: {
                                        if ((nRoots == 2) &&(x1 + 1.30378 < ACCURACY) && (x2 + 0.00871589 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 9: {
                                        if ((nRoots == 2) &&(x1 + 1 < ACCURACY) && (x2 - 7 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    case 10: {
                                        if ((nRoots == 1) && (x1 < ACCURACY))
                                            fprintf(output, "TEST: OK\n");
                                        else {
                                            fprintf(output, "TEST: NO\n");
                                            test_failed = test_failed + 1;
                                            }
                                        break;
                                        }

                                    default: {
                                            fprintf(output, "ERROR\n");
                                            return 0;
                                        }
                                }
                 }

            if (test_failed == 0)
                printf("ALL TESTS ARE DONE\n");
            else
                printf("TESTS FAILED: %d", test_failed);

            fclose(input);
            fclose(output);

        return 0;
        }

//===================================================================================


int manual_test()
        {
        double a = NAN, b = NAN, c = NAN;
        printf("\n"
                   "Square equation solver\n"
                   "Enter 3 coefficients of squad equation a, b, c:\n"
                   "a = ");
        scanf("%lg", &a);

        printf("b = ");
        scanf("%lg", &b);

        printf("c = ");
        scanf("%lg", &c);

        assert(a != NAN);
        assert(b != NAN);
        assert(c != NAN);

        double x1 = 0, x2 = 0;

        if (is_zero(a) == 1)
            {
            int nRoots = 0;
            nRoots = square_solver(a, b, c, &x1, &x2);

            switch (nRoots)
                    {
                    case 0:  printf("No roots!\n");
                             break;

                    case 1:  printf("1 root: x = %lg\n", x1);
                             break;

                    case 2:  printf("2 roots: x1 = %lg, x2 = %lg\n", x1, x2);
                             break;

                    default: printf("ERROR");
                             return 0;
                    }
                }
        else
            {
            int nRoots = linear_solver(b, c, &x1);

            switch (nRoots)
                    {
                    case 0:         printf("No roots!\n");
                                    break;

                    case 1:         printf("1 root: x = %lg\n", x1);
                                    break;

                    case INF_ROOTS: printf("INFTY ROOTS\n");
                                    break;

                    default:        printf("ERROR");
                                    return 0;
                    }

                 }
        return 0;
        }

