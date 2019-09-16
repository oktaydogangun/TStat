/*
 *  Tool for Statistical Operations in Physics
 *
 *  TStat.h
 *
 *  Author: Oktay DOĞANGÜN <oktay.dogangun@gmail.com>
 *  Inspired by: Kıyami ERDİM
 *
 */

#ifndef TSTAT_H
#define TSTAT_H

#include<iostream>

namespace TStat {
    class Double;
    struct Error {
        // The positive and negative errors
        // are held seperately and without 
        // a signiture 
        double plus;
        double minus;
    };

    // The error operator
    Error operator "" _err(long double err);

    // The minus error operator
    Error operator- (Error);

    // Adding two errors
    Error operator +(Error, Error);

    // Sample struct // TODO
    struct Sample {
        unsigned long long sample;
    };

    // Add an error to a mean value
    // and create a Double
    Double operator +(double, Error);

    // Operator for cout stream
    std::ostream &operator<<(std::ostream&, Double const&);

    // The class for the Double
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
                sample.sample = 10000; 
            }

            // Constructor
            Double (double meanv) {
                mean = meanv;
            }

            // Deconstructor
            ~Double(){
            }

            // We have a mean, errors and sample
            double mean;
            Error errors;
            Sample sample;

            // Assignment operators:
            void operator =(const double&);

            // Redundant
            friend Double operator<(Double,double);

            // Add an error to the object
            friend Double operator +(Double, Error);
            
            // Add a positive error to the object
            friend Double operator -(Double, Error);

            // Sample generator operator
            friend Sample operator"" _gen(unsigned long long);

            // Add two measurements with asymmetric errors
            friend Double operator +(Double,Double);

            // Add an integer or double to a measurement
            friend Double operator +(Double,double);
            friend Double operator +(double,Double);

            // Conversion from TStat to double // TODO
            //operator double () const;
            
            // Print via ostream
            std::ostream &Print(std::ostream&) const;
    };
}

#endif
