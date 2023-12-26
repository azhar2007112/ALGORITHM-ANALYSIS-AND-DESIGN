#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 100000;
int dp[101][N];

int func(int ind, int value, vector<int>& coins) {
    if (value == 0) return 1;
    if (ind < 0 || value < 0) return 0;
    if (dp[ind][value] != -1) return dp[ind][value];

    int ways = 0;


    ways += func(ind- 1, value - coins[ind], coins);


    ways += func(ind- 1, value, coins);

    dp[ind][value] = ways;

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
