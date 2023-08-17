#include <iostream>
#include <vector>

using namespace std;
#define mod 1000000007

int solve( int amount , vector<int> &coins , vector<int> &dp){

    if(amount < 0 ) return 0;

    if(amount == 0) return 1;

    else if(dp[amount]!= -1) return dp[amount];

    int ans = 0;

    for(int i = 0 ; i< coins.size() ; i++){
        ans = (ans + solve(amount-coins[i] , coins , dp)) %mod;
    }

    return dp[amount] = ans%mod;
  
}

int main()
{

int n, x;
cin>>n>>x;

vector<int> coins(n);

for(int i = 0 ; i< n ; i++){
    int c ;
    cin>>c;
    coins[i] = c;
}

vector<int> dp(x +1 , -1);

int ans  = solve( x , coins , dp);

if(ans == 1e8){
    ans = -1;
}

cout<<ans;






    
    return 0;
}
