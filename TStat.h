/*
 *  Tool for Statistical Operations in Physics
 *
 *  Author: Oktay DOĞANGÜN <oktay.dogangun@gmail.com>
 *
 *  Inspired by: Kıyami ERDİM
 *
 */

#ifndef TSTAT_H
#define TSTAT_H

#include<iostream>

namespace TStat {
    //class Integer;
    class Double;
    struct Error {
        // The positive and negative errors
        // are held seperately and without 
        // a signiture 
        double plus;
        double minus;
    };

    Error operator "" _err(long double err);
    Error operator- (Error);
    Error operator +(Error, Error);

    struct Sample {
        // Defined as a pointer in order
        // to save from memory if one has
        // many operations going on.
        unsigned long long sample;
    };

    Double operator +(double, Error);
    std::ostream &operator<<(std::ostream&, Double const&);

    class Double {

        private:
        public:
            // Constructor
            Double(){
                // Set mean to 0
                mean =0;

                // and no errors, yet
                errors.plus=0;
                errors.minus=0;

                // Default sample size is 10000
                sample.sample = 10000; //new unsigned long long(10000); 
            }

            Double (double meanv) {
                mean = meanv;
            }

            // Deconstructor
            ~Double(){
                //delete sample.sample;
            }

            // We have a mean, errors and sample
            double mean;
            Error errors;
            Sample sample;

            // Assignment operators:
            void operator =(const double&);
            //Double& operator =(const int&);

            // 
            friend Double operator<(Double,double);
            //friend Double operator<(Double,int);

            // Add an error to the object
            friend Double operator +(Double, Error);
            
            // Add a positive error to the object
            friend Double operator -(Double, Error);

            // Add two errors
            //friend Error operator +(Error, Error);

            // Add a value and an error to get an object
            //friend Double operator +(double, Error);

            // Sample generator operator
            friend Sample operator"" _gen(unsigned long long);

            // Add two measurements with asymmetric errors
            friend Double operator +(Double,Double);

            // Add an integer or double to a measurement
            //friend Double operator +(Double,int);
            friend Double operator +(Double,double);
            //friend Double operator +(int,Double);
            friend Double operator +(double,Double);

            // Conversion from TStat to double
            //operator double () const;
            std::ostream &Print(std::ostream&) const;

            //friend std::ostream &operator<<(std::ostream&, Double const&);
    };

    // kmkmk
    //Double operator +(double, Error);
}

#endif
