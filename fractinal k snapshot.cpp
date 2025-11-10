#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

void fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    double finalVal = 0.0;
    int curW = 0;
    
    for (auto& item : arr) {
        if (curW + item.weight <= W) {
            curW += item.weight;
            finalVal += item.profit;
        } else {
            int remain = W - curW;
            finalVal += item.profit * ((double)remain / item.weight);
            break;
        }
    }
    cout << "Maximum value in Knapsack = " << finalVal << endl;
}

int main() {
    vector<Item> arr = {{10,1}, {15,3}, {7,5}, {8,4}, {9,1}, {4,3}};
    int W = 15;
    fractionalKnapsack(W, arr);
}
