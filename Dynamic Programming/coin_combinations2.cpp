#include <iostream>
#include <vector>

using namespace std;
#define mod 1000000007

int solveSo(int x, vector<int> &coins){

    int n = coins.size();

    vector<int> next(x+1 , 0);
    vector<int> curr(x+1 , 0);

     next[0] = 1;
     curr[0] = 1;

     for(int i = n-1 ; i >= 0 ; i--){
        for(int amount = 1 ; amount <= x ; amount++){

            int inc = 0;

            if(amount >= coins[i]) inc = curr[amount - coins[i]];

            int exc = next[amount];

            curr[amount] = (inc + exc) %mod;

        }

        next = curr;
     }

     return next[x];

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

    cout<<solveSo(x , coins);
    return 0;
}
