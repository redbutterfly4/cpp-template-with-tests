#include "RationalNumber.h"

#include <numeric>

RationalNumber::RationalNumber(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator)
{
    normalization();
}

std::string RationalNumber::toString() const
{
    return std::to_string(numerator_) + " / " + std::to_string(denominator_);
}

void RationalNumber::normalization()
{
    int gcd = std::gcd(numerator_, denominator_);
    if (gcd > 1) {
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
}

void RationalNumber::sum(const RationalNumber &other)
{
    int resDenominator = denominator_ * other.denominator_
            / std::gcd(denominator_,
                       other.denominator_); // НОК
    int resNumerator = (numerator_ * (resDenominator / denominator_))
            + (other.numerator_ * (resDenominator / other.denominator_));
    numerator_ = resNumerator;
    denominator_ = resDenominator;
    normalization();
}

bool RationalNumber::operator==(const RationalNumber &other) const
{
    return (this == &other)
            ? true
            : ((numerator_ == other.numerator_) && (denominator_ == other.denominator_));
}

RationalNumber RationalNumber::operator+(const RationalNumber &other) const
{
    int resDenominator = denominator_ * other.denominator_
            / std::gcd(denominator_,
                       other.denominator_); // НОК
    int resNumerator = (numerator_ * (resDenominator / denominator_))
            + (other.numerator_ * (resDenominator / other.denominator_));
    return RationalNumber(resNumerator, resDenominator);
}

RationalNumber RationalNumber::operator+() const
{
    return RationalNumber(*this);
}

RationalNumber RationalNumber::operator-() const
{
    return RationalNumber(-numerator_, denominator_);
}

RationalNumber RationalNumber::operator++() const {
    return (numerator_ >= 0) ? RationalNumber(numerator_ += denominator_, denominator_) :
}

std::ostream &
operator<<(std::ostream &stream, const RationalNumber &num)
{
    stream << num.toString();
    return stream;
}