#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define mod 1000000007

int solve(int i , int j , vector<vector<char>> &grid , vector<vector<int>> &dp){

    if(i>=grid.size() || j >= grid[0].size() ) return 0;

    if(grid[i][j] == '*') return 0;

    if(i == grid.size()-1 && j== grid[0].size()-1) return 1;

    else if(dp[i][j] != -1) return dp[i][j];

    int right = solve(i , j+1 , grid , dp)%mod;

    int down = solve(i+1 , j , grid , dp)%mod;

    return dp[i][j] = (right + down) %mod;

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<vector<char>> grid(n , vector<char>(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char c ;
            cin>>c;

            grid[i][j] = c;
        }
    }

    vector<vector<int>> dp(n,vector<int>(n,-1));

    int ans = solve(0 , 0 , grid , dp);

    cout<<ans;

    
    return 0;
}
