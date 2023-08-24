#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
#define mod 1000000007


using namespace std;

struct project{
    int start,end,reward;
};
bool compare(project &p1, project &p2){
    return p1.end<p2.end;
}
int findbest(vector<int>&endpoints , int val){

    auto it= lower_bound(endpoints.begin(),endpoints.end(),val);

    if(it==endpoints.begin()){
        return 0;
    }
    else it--;
    
    return it - endpoints.begin()+1;

}
ll solve(vector<project>&p,int n){
    vector<int>endpoints;
    for(int i=0;i<n;i++){
        endpoints.push_back(p[i].end);
    }

    vector<ll> dp(n+1);
    dp[0]=0;

    for(int i=0; i<n; i++){
        ll ans1 = dp[i];
        ll ans2 = p[i].reward;

        int j = findbest(endpoints,p[i].start);

        ans2=(ans2+dp[j]);
        dp[i+1] =max(ans1,ans2);
    }

    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<project>p(n);
    for(int i=0;i<n;i++)
        cin>>p[i].start>>p[i].end>>p[i].reward;

    
    sort(p.begin(),p.end(),compare);

    cout<<solve(p,n)<<endl;


}