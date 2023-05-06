#include "Fraction.hpp"


using namespace ariel;
using namespace std;

    Fraction::Fraction(double num, double den) : numerator(num),denominator(den)
    {
        if (this->denominator == 0)
        {
            __throw_invalid_argument("denominator can't be 0 , math error");
        }
        
        //the defult value left meanning , someone enter Fraction(double)
        if (den == 1 && fmod(num, 1) != 0)
        {
            *this = Fraction((float)num);
        }
        if(den < 0)
        {
            this->numerator /=-1;
            this->denominator /=-1;
        }
        //cout << "newNumerator" << this->numerator << " newDenominator" << this->denominator << endl;
        int gcd = gcdFunc(this->numerator,this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
    }
    Fraction::Fraction(float shever){
        int rounded = round(shever * 1000);
        int gcd = gcdFunc(rounded,1000);
        this->numerator = rounded / gcd;
        this->denominator = 1000 / gcd;
    }

    int Fraction::gcdFunc( int num1, int num2) const
    {   
        
        if (num2 == 0) {
            if(num1==-1){
                return 1;
            }
            return num1;
        } else {
            return gcdFunc(num2, num1 % num2);
        }
    }
    
    Fraction Fraction::operator+(const Fraction& other) const {
        long long n = ((long)this->numerator * (long)other.denominator) + ((long)this->denominator * (long)other.numerator);
        long long d = (long)this->denominator * (long)other.denominator;
        if (n > INT_MAX || d > INT_MAX || n < INT_MIN || d < INT_MIN) {
            throw std::overflow_error("operator overflow");
        }
        int newNumerator = (int)n;
        int newDenominator = (int)d;
        int gcd = gcdFunc(newNumerator,newDenominator);
        return Fraction(newNumerator/gcd , newDenominator/gcd);
    }
    Fraction operator+(const Fraction& other , float shever)
    {
        return other + Fraction(shever);
    }
    Fraction operator+(float shever , const Fraction& other)
    {
        return other + shever;
    }
    
    Fraction Fraction::operator-(const Fraction& other) const {
    // |INT_MIN| = |INT_MAX| + 1 --> -INT_MIN > INT_MAX - operator overflow
    if(other.numerator == INT_MIN || other.denominator == INT_MIN)
    {
        throw std::overflow_error("operator overflow");
    }
    //using Fraction + (-Fraction)
    return (*this + Fraction(other.numerator * (-1) , other.denominator));
    }

    Fraction operator-(const Fraction& other , float shever)
    {
        //using Fraction - Fraction
        return other - (Fraction(shever));
    }
    
    Fraction operator-(float shever , const Fraction& other)
    {
        //using Fraction - Fraction.
        return Fraction(shever) - other;
    }
    
    Fraction Fraction::operator*(const Fraction& other) const {
        long long n = (long)this->numerator * (long)other.numerator;
        long long d = (long)this->denominator * (long)other.denominator;
        if (n > INT_MAX || d > INT_MAX) {
            throw std::overflow_error("Multiplication overflow");
        }
        int newNumerator = (int)n;
        int newDenominator = (int)d;
        //cout << "newNumerator" << newNumerator << " newDenominator" << newDenominator << endl;
        int gcd = gcdFunc(newNumerator,newDenominator);
        return Fraction(newNumerator/gcd , newDenominator/gcd);
    }
    Fraction operator*(const float shever  , const Fraction& other)
    {
        //using Fraction * Fraction
        return other * Fraction(shever);
    }
    Fraction operator*(const Fraction& other , float shever)
    {
        //using float * Fraction
        return shever * other;
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.numerator == 0)
        {
            __throw_runtime_error("can't divide by zero , math error");
        }
        // (a/b) / (c/d) <==> (a/b) * (d/c)
        return ((*this) * Fraction(other.denominator,other.numerator));
    }
    Fraction operator/(const float shever  , const Fraction& other)
    {
        //using Fraction / Fracrtion
        return Fraction(shever) / other;
    }
    Fraction operator/(const Fraction& other , float shever)
    {
        //using Fraction / Fraction
        return other / Fraction(shever);
    }
    
    bool Fraction::operator>(const Fraction& other) const {
        float num1 = (float)this->numerator / (float)this->denominator;
        float num2 = (float)other.numerator / (float)other.denominator;
        return (num1 > num2);
    }
    bool operator>(const Fraction& other,float shever)
    {
        //using Fraction > Fraction
        return other > Fraction(shever);
    }
    bool operator>(float shever , const Fraction& other)
    {
        //using Fraction > Fraction
        return Fraction(shever) > other;
    }
    
    bool Fraction::operator<(const Fraction& other) const {
        float num1 = (float)this->numerator / (float)this->denominator;
        float num2 = (float)other.numerator / (float)other.denominator;
        return (num1 < num2);
    }
    bool operator<(const Fraction& other,float shever)
    {
        //using Fraction < Fraction
        return other < Fraction(shever);
    }
    bool operator<(float shever , const Fraction& other)
    {
        //using Fraction < Float
        return Fraction(shever) < other;
    }
    
    bool Fraction::operator>=(const Fraction& other) const {
        // if x isn't < y --> x >=y 
        bool smaller = (*this) < other;
        return !smaller;
    }
    bool operator>=(const Fraction& other,float shever)
    {
        //using Fraction >= Fraction
        return other >= Fraction(shever);
    }
    bool operator>=(float shever , const Fraction& other)
    {
        //using Fraction >= Float
        return Fraction(shever) >= other;
    }
    
    bool Fraction::operator<=(const Fraction& other) const {
        // if x isn't > y --> x <=y 
        bool bigger = (*this) > other;
        return !bigger;
    }
    bool operator<=(const Fraction& other,float shever)
    {
        //using Fraction <= Fraction
        return other <= Fraction(shever);
    }
    bool operator<=(float shever , const Fraction& other)
    {
        //using Fraction <= Fraction
        return Fraction(shever) <= other;
    }
    
    bool Fraction::operator==(const Fraction& other) const {
        // if x>=y && x<=y --> x==y
        return (((*this) >= other) && ((*this) <= other));
    }
    bool operator==(const Fraction& other,float shever)
    {
        //using Fraction == Fraction
        return other == Fraction(shever);
    }
    bool operator==(float shever , const Fraction& other)
    {
        //using Fraction == float
        return other == shever;
    }
    
    bool Fraction::operator!=(const Fraction& other) const {
        // if x isn't == y --> x!=y
        return !((*this) == other);
    }
    bool operator!=(const Fraction& other,float shever)
    {
        //using Fraction != Fraction
        return other != Fraction(shever);
    }
    bool operator!=(float shever , const Fraction& other)
    {
        //using Fraction != float
        return other != shever;
    }
    
    Fraction& Fraction::operator++() {
        //add one only at end
        this->numerator += this->denominator;
        return *this;
    }
    
    Fraction Fraction::operator++(int) {
        //add one at the begging
        Fraction copy(this->numerator,this->denominator);
        this->numerator += this->denominator;
        return copy;
    }
    
    Fraction& Fraction::operator--() {
        //decrease one only at end
        this->numerator -= this->denominator;
        return *this;
    }
    
    Fraction Fraction::operator--(int) {
        //decrase one at the begging
        Fraction copy(this->numerator,this->denominator);
        this->numerator -= this->denominator;
        return copy;
    }

    ostream& operator<<(ostream& buffer, const Fraction& other) {
        Fraction newFrac(other.numerator, other.denominator);
        //cout << "numerator : "  << newFrac.numerator << "denominator : " << newFrac.denominator << endl;
        buffer << newFrac.numerator << '/' << newFrac.denominator;
        return buffer;
    }

    istream& operator>>(std::istream& input, Fraction& other)
    {
        int num=0, den=0;
        input >> num >> den;
        
        if (den == 0)
        {
            throw runtime_error("denominator in fraction can't be zero");
        }
        else
        {
        other.numerator = num;
        other.denominator = den;
        }
        return input;
    }