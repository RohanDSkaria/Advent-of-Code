#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    int ans=0;
    /*
        PART - 1:
        while(cin>>s){
            reverse(s.begin(),s.end());
            int mx=0;
            char cmx=s[0];
            for(int i=1; i<s.size(); i++){
                mx=max(mx,(s[i]-'0')*10ll+(cmx-'0'));
                cmx=max(cmx,s[i]);
            }
            ans+=mx;
        }
    */
    // PART - 2:
    while(cin>>s){
        int n=s.size(),m=n-12;
        string t;
        for(int i=0; i<n; i++){
            while(t.size() && t.back()<s[i] && m){
                t.pop_back();
                m--;
            }
            t+=s[i];
        }
        t.resize(12);
        ans+=stoll(t);
    }
    cout<<ans<<'\n';
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
/*

*/