#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <string>
#include <iostream>

class RationalNumber
{
public:
    RationalNumber(int numerator = 0, int denominator = 1);
    RationalNumber(const RationalNumber &other) = default;
    RationalNumber &operator=(const RationalNumber &other) = default;
    RationalNumber(RationalNumber &&other) = default;
    RationalNumber &operator=(RationalNumber &&other) = default;
    ~RationalNumber() = default;

    std::string toString() const;
    void sum(const RationalNumber &);

    bool operator==(const RationalNumber &) const;
    RationalNumber operator+(const RationalNumber &) const;
    RationalNumber operator+() const;
    RationalNumber operator-() const;
    RationalNumber operator++() const;

private:
    int numerator_;
    unsigned int denominator_;
    void normalization();

    friend std::ostream &operator<<(std::ostream &, const RationalNumber &);
};

#endif // RATIONAL_NUMBER_H_