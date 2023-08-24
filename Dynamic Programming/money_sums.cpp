
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

 
using namespace std;

int  solve(int i , vector<int> coins , int sum , set <int > &res , vector<vector<int>> &dp){
    if(i >= coins.size()){
        if(sum) res.insert(sum);
        return  0;
    }
    else if(dp[i][sum] != -1) return dp[i][sum];

     int inc = 1 + solve(i+1 ,coins, sum + coins[i] ,res , dp);
     int exc = solve(i+1 ,coins, sum  ,res , dp);

     return dp[i][sum] = max(inc , exc);
}
 
int main()
{

    int n;
    cin>>n;

    vector<int> coins(n);

    for(int i = 0; i< n ; i++){
        cin>>coins[i];
    }

    set <int> res;
    int sum = 0;
    int total = accumulate(coins.begin() , coins.end() , 0);

    vector<vector<int>> dp(n+1 , vector<int>(total +1 , -1));


    int a = solve(0 , coins , sum , res , dp);

    cout << res.size() <<endl;

    for(auto i : res){
        cout<<i<<" ";
    }

    

}