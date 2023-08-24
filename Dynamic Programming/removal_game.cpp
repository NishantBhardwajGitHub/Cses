#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll solve(ll i , ll j ,  vector<ll> &scores , vector<vector<ll>> &dp){

    if(i > j) return 0 ;

    else if(dp[i][j] != -1)  return dp[i][j];

    ll option1 = scores[i] + min(solve(i+2 , j , scores , dp) , solve(i+1 , j-1 , scores , dp));
    ll option2 = scores[j] + min(solve(i , j-2, scores , dp) , solve(i+1 , j-1 , scores , dp));
   

   return dp[i][j] = max(option1 , option2);
    
}

int main()
{
    ll n;
    cin>>n;

    vector<ll> scores(n);

    for(ll i = 0 ; i < n ; i++){
        cin>>scores[i];
    }
    vector<vector<ll>> dp(n+1 , vector<ll>(n+1 ,-1));

    ll ans = solve( 0 , n-1 , scores , dp);

    cout<<ans;


    return 0;
}
