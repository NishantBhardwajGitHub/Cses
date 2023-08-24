#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define mod 1000000007

using namespace std;

int solve(int n , int totalsum , vector<vector<int>> &dp){

    if(n <= 0 || totalsum<0){
        return 0;
    }
    else if(totalsum == 0){
        return 1;
    }

    else if(dp[n][totalsum] != -1) return dp[n][totalsum];

    int inc = 0;

    if(totalsum >= n) inc = solve(n-1,totalsum - n , dp) % mod;

    int exc = solve(n-1 , totalsum , dp) % mod;

    return  dp[n][totalsum] = (inc + exc) %mod;

}

int main()
{

    int n;
    cin>>n;

    int totalsum=  0;

    for(int i = 1; i <= n ; i++){
        totalsum = totalsum+i;
    }

    vector<vector<int>> dp(n+1 , vector<int>(totalsum , -1));

    if(totalsum % 2 == 0) {
        int ans = solve(n , totalsum/2 , dp);
        cout << ans;
         
    }
    else cout<<0;
  
    
    
    return 0;
}

