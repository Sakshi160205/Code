#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int a[], int l, int h, bool rnd) {
    if (rnd) swap(a[l + rand() % (h - l + 1)], a[h]);
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++)
        if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(int a[], int l, int h, bool rnd) {
    if (l < h) {
        int pi = partition(a, l, h, rnd);
        quickSort(a, l, pi - 1, rnd);
        quickSort(a, pi + 1, h, rnd);
    }
}

int main() {
    srand(time(0));
    int a[] = {10, 7, 8, 9, 1, 5}, n = 6;

    cout << "Deterministic Quick Sort:\n";
    quickSort(a, 0, n - 1, false);
    for (int x : a) cout << x << " ";

    int b[] = {10, 7, 8, 9, 1, 5};
    cout << "\n\nRandomized Quick Sort:\n";
    quickSort(b, 0, n - 1, true);
    for (int x : b) cout << x << " ";
}
