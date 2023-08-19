#include <iostream>
#include <vector>


using namespace std;

  int solve(string &word1 , string& word2 , int i , int j , vector<vector<int>> &dp){

        if(j == word2.length() && i < word1.length()) return word1.length() - i;
        if(i == word1.length() && j < word2.length()) return word2.length() - j;
        if(i== word1.length() && j == word2.length()) return 0;

        else if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(word1 , word2 , i+1 , j+1 , dp);

        else{
            int insertword = 1 + solve(word1 , word2 , i , j+1 , dp);
            int deleteword = 1 + solve(word1 , word2 , i+1 , j , dp);
            int replaceword = 1 + solve(word1 , word2 , i+1 , j+1 , dp);


            return dp[i][j] = min(insertword , min(deleteword , replaceword));
        }

    }
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.length() , vector<int>(word2.length() , -1));

        return solve(word1 , word2 , 0 , 0 , dp );
        
    }


int main(int argc, char const *argv[])
{
    string n;
    string m;
    cin>>n>>m;

    int ans= minDistance(n , m);
    cout<<ans;


    return 0;
}
