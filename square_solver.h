
//===================================================================================

/*!
    \brief This function solves quadratic equations
    \param[in] a coefficient of quadratic equation
    \param[in] b coefficient of quadratic equation
    \param[in] c coefficient of quadratic equation
    \param[out] x1 solution of quadratic equation
    \param[out] x2 solution of quadratic equation
    \return Number of roots

    \code
    int square_solver(double a, double b, double c, double* x1, double* x2)
    {
        assert(x1 != NULL);
        assert(x2 != NULL);
        assert(x1 !=   x2);
        assert(a  !=  NAN);
        assert(b  !=  NAN);
        assert(c  !=  NAN);

        double discr = b * b - 4 * a * c;

        if(discr < 0)
        {
            return NO_ROOTS;
        }

        if(is_zero(discr))
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
    \endcode
*/

int square_solver(double a, double b, double c, double* x1, double* x2);

//===================================================================================

int square_solver(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 !=   x2);
    assert(a  !=  NAN);
    assert(b  !=  NAN);
    assert(c  !=  NAN);

    double discr = b * b - 4 * a * c;

    if(discr < 0)
    {
        return NO_ROOTS;
    }

    if(is_zero(discr))
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
