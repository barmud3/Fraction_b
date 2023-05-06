#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

namespace ariel {};
    class Fraction {
        private:
            int numerator;
            int denominator;
        
        public:
            //Fraction(int num = 1, int den = 1);
            Fraction(double num = 1.0, double den = 1.0);
            Fraction(float shever);

            Fraction operator+(const Fraction& other) const;
            friend Fraction operator+(const Fraction& other , float shever);
            friend Fraction operator+(float shever , const Fraction& other);

            Fraction operator-(const Fraction& other) const;
            friend Fraction operator-(const Fraction& other , float shever);
            friend Fraction operator-(float shever , const Fraction& other);

            Fraction operator*(const Fraction& other) const;
            friend Fraction operator*(const Fraction& other , float shever);
            friend Fraction operator*( float shever ,const Fraction& other);

            Fraction operator/(const Fraction& other) const;
            friend Fraction operator/(const Fraction& other , float shever);
            friend Fraction operator/( float shever ,const Fraction& other);

            bool operator>(const Fraction& other) const;
            friend bool operator>(const Fraction& other, float shever);
            friend bool operator>( float shever , const Fraction& other);

            bool operator<(const Fraction& other) const;
            friend bool operator<(const Fraction& other , float shever );
            friend bool operator<( float shever , const Fraction& other );

            bool operator>=(const Fraction& other) const;
            friend bool operator>=(const Fraction& other , float shever );
            friend bool operator>=( float shever , const Fraction& other );

            bool operator<=(const Fraction& other) const;
            friend bool operator<=(const Fraction& other , float shever );
            friend bool operator<=( float shever , const Fraction& other );

            bool operator==(const Fraction& other) const;
            friend bool operator==(const Fraction& other , float shever );
            friend bool operator==( float shever , const Fraction& other );

            bool operator!=(const Fraction& other) const;
            friend bool operator<(const Fraction& other , float shever );
            friend bool operator<( float shever , const Fraction& other );

            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);

            friend std::ostream& operator<<(ostream& buffer, const Fraction& other);

            friend std::istream& operator>>(std::istream& input, Fraction& other);

            int gcdFunc(int num1, int num2) const;

            int getNumerator() const {return this->numerator;}
            int getDenominator() const {return this->denominator;}
            
    };

#endif
