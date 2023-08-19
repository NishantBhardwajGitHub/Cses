#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int n = 1000000;
ll dp[1000001][2];

using namespace std;



int main()
{
  fast_io;
   int t = 1; 
   while(t--){
        dp[n+1][0] = dp[n+1][1] = 1;
 
        for(int i = n; i >= 2; i--){
            ll op1 = (dp[i+1][1] + dp[i+1][0]) % mod;
            ll op2 = dp[i+1][0];
            ll op3 = (2*dp[i+1][0]) % mod;
            ll op4 = dp[i+1][1];
 
            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;
        }
 
        int q; cin >> q;
        while(q--){
            int query; cin >> query;
            cout << (dp[1000000 - query + 2][1] + dp[1000000 - query + 2][0]) % mod << '\n';
        }
        return 0;
 
}
}
