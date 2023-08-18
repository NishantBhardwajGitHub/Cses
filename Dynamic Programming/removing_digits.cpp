#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


#define mod 1000000007

using namespace std;

int digits(int n , vector<int> &dp){

    if(n < 0) return INT_MAX - 1;
    else if(n == 0) return 0;

    else if(dp[n] != -1) return dp[n];

    int num = n;
    int  ans = INT_MAX-1;

    while(num != 0){

        if(num % 10 != 0){
            ans = min(ans , 1 + digits(n - (num%10) , dp));
        }
        num/=10;

    }

    return dp[n]= ans;

}


int main()
{

    int n;

    cin>>n ;

    vector<int> dp(n+1, -1);
    int ans = digits(n ,dp);

    cout << ans;
    
    return 0;
}
