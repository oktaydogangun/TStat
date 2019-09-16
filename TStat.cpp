#include"TStat.h"

using namespace TStat;
/*
 * Assignment
 */   
void TStat::Double::operator =(const double &meanv)
{
    mean = meanv;
}

/*
TStat::Double& TStat::operator =(const int &meanv)
{
    mean = meanv;
    return *this;
}
*/
/*
 * Conversion from TStat to double
 
TStat::Double::operator double() const
{
    return mean;
}


 * Error operator
 *
 * Example:
 *
 * 1.35_e
 *
 * will give an error of +1.35 and -0.00
 *
 */

//namespace TStat{
TStat::Error TStat::operator"" _err(long double err) {
        TStat::Error error;
        error.plus = err;
        error.minus = 0;
        return error;
    }
//}

/*
 * Printing std::cout for a TStat
 *
 * Example:
 *
 * std::std::cout << 4.5 +0.5_e -0.6_e << std::std::endl; 
 */
std::ostream& TStat::Double::Print(std::ostream& os) const
{
    os  << mean << " (+" 
        << errors.plus << ", -" 
        << errors.minus << ")";
    return os;
}

std::ostream& TStat::operator<<(std::ostream& os, TStat::Double const &obj)
{
    return obj.Print(os);
}

/*
 * Generating sample for distribution
 */
TStat::Sample TStat::operator"" _gen(unsigned long long sample) {
    return {sample};//{new unsigned long long (sample)};
}

/*
 * Negative errors handled by a unary operator
 *
 * Example:
 *
 * -0.45_e
 *
 * will give an error of +0.00 and -0.45
 * by first creating 0.45_e and swapping 
 * plus and minus
 *
 */
TStat::Error TStat::operator-(TStat::Error err) {
    err.minus = err.plus;
    err.plus = 0;
    return err;
}

/*
 * Assigning an error to a TStat measurement
 *
 * Example:
 *
 * TStat measurement1;
 * measurement1 = measurement1 + 0.45_e;
 *
 */
TStat::Double TStat::operator +(TStat::Double value, TStat::Error err) {
    if(err.minus == 0)
        value.errors.plus = err.plus;
    else if(err.plus == 0)
        value.errors.minus = err.minus;
    else
        value.errors = err;
    return value;
}

/*
 * Shortcut for assigning negative errors
 * to a measurement
 */
TStat::Double TStat::operator -(TStat::Double value, TStat::Error err) {
    return (value + (-err));
}

/*
 * Adding two errors
 */
TStat::Error TStat::operator +(TStat::Error err1, TStat::Error err2) {
    if(!((err1.plus==0 && err2.minus==0) || 
            (err2.plus==0 && err1.minus==0))) 
        return TStat::Error();

    TStat::Error err;
    err.plus = err1.plus + err2.plus;
    err.minus = err1.minus + err2.minus;
    return err;

}

// Forming a TStat with a double and an error
TStat::Double TStat::operator+ (double mean, TStat::Error err){
    TStat::Double value;
    value.mean = mean;
    value.errors.plus = err.plus;
    value.errors.minus = err.minus;
    return value; 
}

/*
 */
TStat::Double TStat::operator<(TStat::Double value, double err)
{
    if(err > 0) value.errors.plus = err;
    else if(err < 0) value.errors.minus = err;
    return value;
}

/*
 
TStat::Double TStat::operator<(TStat::Double value, int err)
{
    if(err > 0) value.errors.plus = err;
    else if(err < 0) value.errors.minus = err;
    return value;
}


 * Adding two measurements
 */
TStat::Double TStat::operator +(TStat::Double avalue, TStat::Double bvalue)
{
    TStat::Double value;
    value.mean = avalue.mean+bvalue.mean;
    std::cout << "NOT IMPLEMENTED YET" << std::endl;
    return value;
}
/*
TStat::Integer operator +(TStat::Integer avalue, int bvalue)
{
    TStat::Integer value;
    value.mean = avalue.mean+bvalue;
    return value;
}

TStat::Double operator +(TStat::Integer avalue, TStat::Double bvalue)
{
    TStat value;
    value.mean = avalue+bvalue.mean;
    return value;
}
*/
TStat::Double TStat::operator +(TStat::Double avalue, double bvalue)
{
    TStat::Double value;
    value.mean = avalue.mean+bvalue;
    return value;
}

TStat::Double TStat::operator +(double avalue, TStat::Double bvalue)
{
    TStat::Double value;
    value.mean = avalue+bvalue.mean;
    return value;
}


