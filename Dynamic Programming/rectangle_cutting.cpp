#include <iostream>
#include <vector>

using namespace std;

int solve(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int h = 1; h <= a; h++)
    {
        for (int w = 1; w <= b; w++)
        {

            if (h != w)
            {
                int ans = 1e8;

                for (int i = 1; i < h; i++)
                {

                    ans = min(ans, 1 + dp[h - i][w] + dp[i][w]);
                }

                for (int i = 1; i < w; i++)
                {

                    ans = min(ans, 1 + dp[h][w - i] + dp[h][i]);
                }

                dp[h][w] = ans;
            }
        }
    }

    return dp[a][b];
}
int main(int argc, char const *argv[])
{

    int a, b;

    cin >> a >> b;

    int ans = solve(a, b);
    cout << ans;

    return 0;
}
