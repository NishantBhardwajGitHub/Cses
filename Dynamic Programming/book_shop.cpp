#include <iostream>
#include <vector>

using namespace std;

int solveSo(int cost , int n , vector<int> &prices , vector<int> &pages){
    vector<vector<int>> dp(n+1 , vector<int>(cost+1 , 0));

    for(int i = n-1 ; i>= 0 ; i--){
        for(int maxcost = 1 ; maxcost <= cost ; maxcost++){

            int inc = 0;

            if(maxcost>=prices[i]) inc = pages[i] + dp[i+1][maxcost - prices[i]];

            int exc = dp[i+1][maxcost];

            dp[i][maxcost] = max(inc , exc);

        }
    }
    return dp[0][cost];
}

int main(int argc, char const *argv[])
{
    int n,x;
    cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);

    for(int i = 0 ; i<n ; i++){
        int p;
        cin>>p;
        prices[i]=p;
    }
    for(int i = 0 ; i< n ; i++){
        int p;
        cin>>p;
        pages[i]=p;
    }
    int ans = solveSo(x , n , prices , pages);
    cout<<ans;
    return 0;
}
