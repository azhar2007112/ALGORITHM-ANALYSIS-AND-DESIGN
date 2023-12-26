#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, int V, vector<int>& wt, vector<int>& val, vector<int>& volume, int n) {
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
    int n;
    cout << "item "<<endl;
    cin >> n;

    vector<int> profit(n);
    vector<int> weight(n);
    vector<int> volume(n);

    cout << "weight-volume-profit" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> volume[i] >> profit[i];
    }

    int W;
    int V;
    cout << "capacity";
    cin >> W;
    cout << "volume";
    cin >> V;

    int maxProfit = knapSack(W, V, weight, profit, volume, n);
    cout << "profit" << maxProfit << endl;

    return 0;
}

