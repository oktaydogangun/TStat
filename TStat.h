/*
 *  Tool for Statistical Operations in Physics
 *
 *  Author: Oktay DOĞANGÜN <oktay.dogangun@gmail.com>
 *
 *  Inspired by: Kıyami ERDİM
 *
 */

class TStat {

    private:
        struct Error
        {
            // The positive and negative errors
            // are held seperately and without 
            // a signiture 
            Double_t plus;
            Double_t minus;
        };

        struct Sample {
            // Defined as a pointer in order
            // to save from memory if one has
            // many operations going on.
            unsigned long long *sample;
        };

    public:
        // Constructor
        TStat(){
            // Set mean to 0
            mean =0;
            // and no errors, yet
            errors.plus=0;
            errors.minus=0;

            // Default sample size is 10000
            sample.sample = new unsigned long long(10000); 
        }

        // Deconstructor
        ~TStat(){
            delete sampla.sample;
        }

        // We have a mean, errors and sample
        Double_t mean;
        Error errors;
        Sample sample;

        // Assignment operators:
        TStat& operator =(const Double_t&);
        TStat& operator =(const Int_t&);

        // 
        friend TStat operator<(TStat,Double_t);
        friend TStat operator<(TStat,Int_t);

        // Error operator
        friend Error operator"" _e(long double);

        // Handles negative errors
        friend Error operator- (Error);

        // Add an error to the object
        friend TStat operator +(TStat, Error);
        
        // Add a positive error to the object
        friend TStat operator -(TStat, Error);

        // Add two errors
        friend Error operator +(Error, Error);

        // Add a value and an error to get an object
        friend TStat operator +(Double_t, Error);

        // Sample generator operator
        friend Sample operator"" _gen(unsigned long long);

        // Add two measurements with asymmetric errors
        friend TStat operator +(TStat,TStat);

        // Add an integer or double to a measurement
        friend TStat operator +(TStat,Int_t);
        friend TStat operator +(TStat,Double_t);
        friend TStat operator +(Int_t,TStat);
        friend TStat operator +(Double_t,TStat);

        // Conversion from TStat to double
        operator Double_t () const;
};

