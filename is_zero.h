
const double ACCURACY = 1E-5;   ///< Const for accuracy of calculations

/*!
    \brief This function determines is value == 0 or not
    \param[in] value
    \return 0 if value >= ACCURACY
            1 if value < ACCURACY
    \code
    int is_zero(double value)
    {
        if(fabs(value) >= ACCURACY)
        return 0;
    return 1;
    }
    \endcode
*/

int is_zero(double value);

//===================================================================================

int is_zero(double value)
{
    if(fabs(value) >= ACCURACY)
    return 0;   //if value > 0
    return 1;   //if value == 0
}
