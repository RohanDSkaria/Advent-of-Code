#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s,t="+*",k;
    vector<int> a;
    while(cin>>s){
        bool ya=0;
        for(char c:t){
            if(s.find(c)!=-1){
                k+=c;
                ya=1;
                break;
            }
        }
        if(!ya) a.push_back(stoll(s));
    }
    int n=k.size(),m=a.size();
    vector<int> ans(n,-1);
    for(int i=0; i<m; i++){
        if(ans[i%n]==-1) ans[i%n]=(k[i%n]=='*');
        if(k[i%n]=='+') ans[i%n]+=a[i];
        else ans[i%n]*=a[i];
    }
    cout<<accumulate(ans.begin(),ans.end(),0ll)<<'\n';
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
/*

*/