#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, int V, int wt[], int val[], int volume[], int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(W + 1, vector<int>(V + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            for (int v = 1; v <= V; ++v) {
                if (wt[i - 1] <= w && volume[i - 1] <= v) {
                    dp[i][w][v] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]][v - volume[i - 1]], dp[i - 1][w][v]);
                } else {
                    dp[i][w][v] = dp[i - 1][w][v];
                }
            }
        }
    }

    return dp[n][W][V];
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int volume[] = {5, 10, 15};
    int W = 50;
    int V = 25;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << knapSack(W, V, weight, profit, volume, n);
    return 0;
}

