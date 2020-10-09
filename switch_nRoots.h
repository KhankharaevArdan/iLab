
const int INF_ROOTS = -1;       ///< This const means infty roots
const int NO_ROOTS = 0;         ///< This const means no roots

//===================================================================================

/*!
    \brief This function prints solutions
    \param[in] nRoots number of solutions
    \param[out] x1 solution of quadratic equation
    \param[out] x2 solution of quadratic equation

    \code
    void switch_nRoots(int nRoots, double x1, double x2)
    {
        switch(nRoots)
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
    \endcode
*/

void switch_nRoots(int nRoots, double x1, double x2);

//===================================================================================

void switch_nRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case NO_ROOTS:  printf("No roots!\n");
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
