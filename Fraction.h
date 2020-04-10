//
// Created by gaeta on 01.04.2020.
//

#ifndef INF2_LABO4_FRACTION_H
#define INF2_LABO4_FRACTION_H

#include <iostream>

template<typename T>
class Fraction;

template<typename T>
std::ostream &operator<<(std::ostream &os, const Fraction<T> &fra);

template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs);

template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs);

template<typename T>
class Fraction {
    friend std::ostream &operator<<<T>(std::ostream &os, const Fraction<T> &fra);

    friend Fraction<T> operator+<T>(Fraction<T> lhs, const Fraction<T> &rhs);

    friend Fraction<T> operator*<T>(Fraction<T> lhs, const Fraction<T> &rhs);

private:
    T nominator;
    T denominator;
public:
    Fraction(T nominator, T denominator) : nominator(nominator), denominator(denominator) {};

    Fraction<T> simplify();

    bool identity(Fraction<T> fraction);

    bool operator==(Fraction<T> &rhs);

    Fraction<T> operator+=(const Fraction<T> &rhs);

    Fraction<T> operator*=(const Fraction<T> &rhs);

    template<typename U>
    operator U();
};

#include "FractionImpl.h"

#endif //INF2_LABO4_FRACTION_H
