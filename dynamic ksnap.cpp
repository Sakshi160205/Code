#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    vector<int> val = {2, 3, 1, 4};
    vector<int> wt = {3, 4, 6, 5};
    int W = 8;
    cout << "Maximum profit = " << knapSack(W, wt, val, val.size());
}
