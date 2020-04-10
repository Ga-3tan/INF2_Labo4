#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction<int> f1(3, 5);
    Fraction<int> f2(5, 6);
    Fraction<int> f3(4, 6);
    Fraction<int> f4(15, 24);
    Fraction<int> f5(5, 8);

    cout << f1 << endl;
    cout << (f1 * f2).simplify() << endl;
    cout << f3.simplify() << endl;
    cout << f1 + f2 << endl;
    f1 += f2;
    cout << f1 << endl;
    cout << f1 * f2 << endl;
    f1 *= f2;
    cout << f1 << endl;
    cout << (float) f1 << endl;
    cout << (double) f1 << endl;
    cout << f1.identity(f2) << endl;
    f1 = (f2 * f3);
    cout << f1.identity(f2 * f3) << endl;
    cout << (f4 == f5) << endl;

    return 0;
}
