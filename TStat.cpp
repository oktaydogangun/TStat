#include"TStat.h"

/*
 * Assignment
 */   
TStat& TStat::operator =(const Double_t &meanv)
{
    mean = meanv;
    return *this;
}

TStat& TStat::operator =(const Int_t &meanv)
{
    mean = meanv;
    return *this;
}

/*
 * Conversion from TStat to double
 */
TStat::operator Double_t() const
{
    return mean;
}

/*
 * Error operator
 *
 * Example:
 *
 * 1.35_e
 *
 * will give an error of +1.35 and -0.00
 *
 */
TStat::Error operator"" _e(long double err) {
    TStat::Error error;
    error.plus = err;
    error.minus = 0;
    return error;
}

/*
 * Printing cout for a TStat
 *
 * Example:
 *
 * std::cout << 4.5 +0.5_e -0.6_e << std::endl; 
 */
std::ostream& operator<<(std::ostream& os, const TStat& obj)
{
    os  << obj.mean << " (+" 
        << obj.errors.plus << ", " 
        << obj.errors.minus << ")";
    return os;
}

/*
 * Generating sample for distribution
 */
TStat::Sample operator"" _gen(unsigned long long sample) {
    return {new unsigned long long (sample)};
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
TStat::Error operator-(TStat::Error err) {
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
TStat operator +(TStat value, TStat::Error err) {
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
TStat operator -(TStat value, TStat::Error err) {
    return (value + -err);
}

/*
 * Adding two errors
 */
TStat::Error operator +(TStat::Error err1, TStat::Error err2) {
    if(!((err1.plus==0 && err2.minus==0) || 
            (err2.plus==0 && err1.minus==0))) 
        return TStat::Error();

    TStat::Error err;
    err.plus = err1.plus + err2.plus;
    err.minus = err1.minus + err2.minus;
    return err;

}

// Forming a TStat with a double and an error
TStat operator+ (Double_t mean, TStat::Error err){
    TStat value;
    value.mean = mean;
    return value+err; 
}

/*
 */
TStat operator<(TStat value, Double_t err)
{
    if(err > 0) value.errors.plus = err;
    else if(err < 0) value.errors.minus = err;
    return value;
}

/*
 */
TStat operator<(TStat value, Int_t err)
{
    if(err > 0) value.errors.plus = err;
    else if(err < 0) value.errors.minus = err;
    return value;
}

/*
 * Adding two measurements
 */
TStat operator +(TStat avalue, TStat bvalue)
{
    TStat value;
    value.mean = avalue.mean+bvalue.mean;
    cout << "NOT IMPLEMENTED YET" << endl;
    return value;
}

TStat operator +(TStat avalue, Int_t bvalue)
{
    TStat value;
    value.mean = avalue.mean+bvalue;
    return value;
}

TStat operator +(Int_t avalue, TStat bvalue)
{
    TStat value;
    value.mean = avalue+bvalue.mean;
    return value;
}

TStat operator +(TStat avalue, Double_t bvalue)
{
    TStat value;
    value.mean = avalue.mean+bvalue;
    return value;
}

TStat operator +(Double_t avalue, TStat bvalue)
{
    TStat value;
    value.mean = avalue+bvalue.mean;
    return value;
}


