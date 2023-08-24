#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solve(vector<int> &nums){
     vector<int> ans;

        ans.push_back(nums[0]);

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin() , ans.end() , nums[i] ) - ans.begin();

                ans[index]=nums[i];
            }
        }
        return ans.size();
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }

    int ans = solve(nums);

    cout<<ans;


    return 0;
}
