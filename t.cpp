#include <bits/stdc++.h>
using namespace std;

int weight[100], value[100], volume[100];
int DP[100][100][100];

int knapsack(int item, int weight_left, int volume_left)
{
    if (item < 0 || weight_left <= 0 || volume_left <= 0)return 0;
    if (DP[item][weight_left][volume_left] != -1)return DP[item][weight_left][volume_left];
    int ans = knapsack(item - 1, weight_left, volume_left);
    if (weight[item] <= weight_left && volume[item] <= volume_left)
    {
        ans = max(ans, knapsack(item - 1, weight_left - weight[item], volume_left - volume[item]) + value[item]);
    }
    return DP[item][weight_left][volume_left] = ans;
}

int main()
{
    int n, w, v;

    cin >> n >> w >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> volume[i] >> value[i];
    }

    memset(DP, -1, sizeof(DP));

    cout << knapsack(n - 1, w, v);
}
