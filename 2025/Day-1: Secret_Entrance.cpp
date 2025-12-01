#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    /*
        PART - 1:
        string s;
        int arrow=50,ans=0;
        while(cin>>s){
            int k=stoll(s.substr(1))%100;
            if(s[0]=='L') arrow=(arrow-k+100)%100;
            else arrow=(arrow+k)%100;
            ans+=!arrow;
        }
        cout<<ans<<'\n';
    */
    // PART - 2:
    string s;
    int arrow=50,ans=0;
    while(cin>>s){
        int k=stoll(s.substr(1));
        ans+=k/100;
        k%=100;
        if(s[0]=='L'){
            ans+=arrow && arrow-k<1;
            arrow=(arrow-k+100)%100;
        }
        else{
            ans+=arrow && arrow+k>99;
            arrow=(arrow+k)%100;
        }
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