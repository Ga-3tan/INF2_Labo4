//
// Created by gaeta on 01.04.2020.
//

#ifndef INF2_LABO4_FRACTIONIMPL_H
#define INF2_LABO4_FRACTIONIMPL_H

#include "Fraction.h"

template<typename T>
Fraction<T> Fraction<T>::simplify() {
    T A = this->nominator;
    T B = this->denominator;
    T R = A % B;

    // algoritme pour la simplification
    while (R != 0) {
        A = B;
        B = R;
        R = A % B;
    }

    return Fraction<T>(this->nominator / B, this->denominator / B);
}

template<typename T>
bool Fraction<T>::identity(Fraction<T> fraction) {
    return this->nominator == fraction.nominator && this->denominator == fraction.denominator;
}

template<typename T>
bool Fraction<T>::operator==(Fraction<T> &rhs) {
    Fraction A = this->simplify();
    Fraction B = rhs.simplify();
    return A.nominator == B.nominator && A.denominator == B.denominator;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Fraction<T> &fra) {
    return os << fra.nominator << "/" << fra.denominator;
}

template<typename T>
Fraction<T> Fraction<T>::operator+=(const Fraction<T> &rhs) {
    auto nomi1 = this->nominator;
    auto deno1 = this->denominator;
    auto nomi2 = rhs.nominator;
    auto deno2 = rhs.denominator;

    // algorithme pour trouver le pgdc des deux denominateur
    while (deno1 != deno2) {
        while (deno1 > deno2) deno2 = deno2 + rhs.denominator;
        while (deno1 < deno2) deno1 = deno1 + this->denominator;
    }
    // multiplication des nominateurs par la division du nouveau denominateur
    nomi1 *= deno1 / this->denominator;
    nomi2 *= deno2 / rhs.denominator;

    this->nominator = nomi1 + nomi2;
    this->denominator = deno1;

    return *this;
}

template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs += rhs;
    return lhs;
}

template<typename T>
Fraction<T> Fraction<T>::operator*=(const Fraction<T> &rhs) {
    this->nominator *= rhs.nominator;
    this->denominator *= rhs.denominator;
    return *this;
}

template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs *= rhs;
    return lhs;
}

template<typename T>
template<typename U>
Fraction<T>::operator U() {
    return U(this->nominator) / U(this->denominator);
}


#endif //INF2_LABO4_FRACTIONIMPL_H
