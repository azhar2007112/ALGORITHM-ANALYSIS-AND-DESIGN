#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 100000;
int dp[101][N];

int func(int ind, int amnt, vector<int>& coins) {
    if (amnt == 0) return 1;
    if (ind < 0 || amnt < 0) return 0;
    if (dp[ind][amnt] != -1) return dp[ind][amnt];

    int ways = 0;

    ways += func(ind, amnt - coins[ind], coins);
    ways += func(ind - 1, amnt, coins);

    dp[ind][amnt] = ways;

    return ways;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, w;

    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> w;

    int result = func(n - 1, w, coins);
    cout << result << endl;

    return 0;
}
