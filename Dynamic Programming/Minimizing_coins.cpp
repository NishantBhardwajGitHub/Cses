#include <iostream>
#include <vector>

using namespace std;
#define mod 1000000007

int solve(int amount , vector<int> &coins){
        
        int n = coins.size();

        vector<int> next(amount +1);
        vector<int> curr(amount +1);


        for(int i = 0 ; i<=amount ; i++){
            next[i] = 0;
        }

        next[0] = 1;
        curr[0] = 1;

        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = 1 ; j <= amount ; j++){

                int inc = 0;

                if(j >= coins[i]) inc = curr[j-coins[i]] % mod;

                int exc = next[j];

                curr[j] = (inc + exc) % mod;

            }

            next = curr;
        }

        return next[amount];

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

int ans  = solve(x , coins );

if(ans == 1e8){
    ans = -1;
}

cout<<ans;

    
    return 0;
}
