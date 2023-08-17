#include <iostream>
#include <vector>

#define mod 1000000007



using namespace std;
int solve(int n , vector<int> &dp){

    if(n < 0) return 0;
    else if(n==0) return 1;
    else if(dp[n]!= -1) return dp[n];
  

    int ans = 0;

    for(int i = 1 ; i< 7 ; i++){
        ans =  (ans + solve(n - i , dp))%mod;
    }
    return dp[n] = ans%mod;

}

int comb(int n){

  vector<int> dp(n+1 , -1);

    return solve(n , dp);

}

int main()
{

    int n;

    cin>>n ;
    int ans = comb(n);

  cout << ans;
    
    return 0;
}
