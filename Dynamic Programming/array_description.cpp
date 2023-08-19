#include <iostream>
#include <vector>
#include <limits.h>

#define mod 1000000007;
#define ll long long int

using namespace std;

ll helper(ll i, ll x, ll m, vector<ll> &arr, vector<vector<ll>> &dp){

    if (i == (ll)arr.size())
    {
        return 1;
    }
    if (dp[i][x] != -1)
        return dp[i][x];

    if (arr[i] == 0)
    {
        ll ans1 = helper(i + 1, x, m, arr, dp) % mod;

        ll ans2 = 0;
        if (x - 1 >= 1) ans2 = helper(i + 1, x - 1, m, arr, dp) % mod;

        ll ans3 = 0;
        if (x + 1 <= m) ans3 = helper(i + 1, x + 1, m, arr, dp) % mod;

        return dp[i][x] = (ans1 + ans2 + ans3) % mod;
    }
    else
    {
        if (abs(arr[i] - x) <= 1)
        {
            return dp[i][x] = helper(i + 1, arr[i], m, arr, dp) % mod;
        }
        else
            return dp[i][x] = 0;
    }
}

int main()
{
    ll n, m;

    cin >> n >> m;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr[i] = in;
    }

    ll ans = 0;

    vector<vector<ll>> dp(n + 1, vector<ll>(m+1, -1));

    if (arr[0] == 0){
        for (ll i = 1; i <= m; i++){
            ans = (ans + helper(1, i, m, arr, dp)) % mod;
        }
    }
    else
    {
        ans = helper(1, arr[0], m, arr, dp) % mod;
    }

    cout << ans;

    return 0;

}
