
//===================================================================================

/*!
    \brief This function solves linear equations
    \param[in] b coefficient of linear equation bx + c = 0
    \param[in] c coefficient of linear equation bx + c = 0
    \param[out] x1 solution of linear equation bx + c = 0
    \return Number of roots

    \code
    int linear_solver(double b, double c, double* x1)
    {
        assert(x1 != NULL);
        assert(b  != NAN);
        assert(c  != NAN);

        if(is_zero(b) && is_zero(c))
        {
            return INF_ROOTS;
        }

        if(is_zero(b) && !is_zero(c))
        {
            return NO_ROOTS;
        }

        if(!is_zero(b) && is_zero(c))
        {
            *x1 = 0;
            return 1;
        }

        if(!is_zero(b) && !is_zero(c))
        {
            *x1 = -c / b;
            return 1;
        }
    return 3;
    }
    \endcode
*/

int linear_solver(double b, double c, double* x1);

//===================================================================================

int linear_solver(double b, double c, double* x1)
{
    assert(x1 != NULL);
    assert(b  != NAN);
    assert(c  != NAN);

    if(is_zero(b) && is_zero(c))
    {
        return INF_ROOTS;
    }

    if(is_zero(b) && !is_zero(c))
    {
        return NO_ROOTS;
    }

    if(!is_zero(b) && is_zero(c))
    {
        *x1 = 0;
        return 1;
    }

    if(!is_zero(b) && !is_zero(c))
    {
        *x1 = -c / b;
        return 1;
    }
return 3;
}

