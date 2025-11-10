#include <iostream>
using namespace std;

// Recursive
int fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Non-Recursive
void fib_nonrec(int n) {
    int a = 0, b = 1, c;
    cout << "Fibonacci Series: " << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n = 10;
    fib_nonrec(n);
    cout << "Recursive Fibonacci Series: ";
    for (int i = 0; i < n; i++)
        cout << fib_rec(i) << " ";
}
