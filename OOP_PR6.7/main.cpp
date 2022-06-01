#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include "Predicate.h"
using namespace std;

int main() {
    int a1[5] = { 1, -2, 0, 4, -5 };
    int a2[5] = { 1, -2, 0, 4, -5 };
    int a3[5] = { 1, -2, 0, 4, -5 };
    int b[5] = { 0, 0, 0, 0, 0 };
    int c[5] = { 0, 0, 0, 0, 0 };
    int d[5] = { 0, 0, 0, 0, 0 };
    
    cout << "a1 before:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a1[i] << ' ';
    cout << endl;
    erase_copy(&a1[0], &a1[5], &b[0]);
    cout << "a1 after:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a1[i] << ' ';
    cout << endl;
    cout << "b:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << endl << endl;
    
    Predicate<int> *zero = new Negative<int>();
    cout << "a2 before:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a2[i] << ' ';
    cout << endl;
    int n = erase_copy_if(&a2[0], &a2[5], &c[0], *zero);
    cout << "a2 after:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a2[i] << ' ';
    cout << endl;
    cout << "c:" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++)
        cout << c[i] << ' ';
    cout << endl << endl;
    

    Predicate<int> *pos = new Positive<int>();
    cout << "a3 before:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a3[i] << ' ';
    cout << endl;
    n = erase_copy_if(&a3[0], &a3[5], &d[0], *pos);
    cout << "a3 after:" << endl;
    cout << "   ";
    for (int i = 0; i < 5; i++)
        cout << a3[i] << ' ';
    cout << endl;
    cout << "d:" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++)
        cout << d[i] << ' ';
    cout << endl << endl;
    
    return 0;
}
