#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    vector<pair<int,int>> a;
    int ans=0;
    // PART - 1:
    // while(cin>>s){
    //     int k=s.find('-');
    //     if(k!=-1) a.push_back({stoll(s.substr(0,k)),stoll(s.substr(k+1))});
    //     else{
    //         k=stoll(s);
    //         for(auto &[x,y]:a){
    //             if(k>=x && k<=y){
    //                 ans++;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<'\n';
    // PART - 2:
    while(cin>>s){
        int k=s.find('-');
        if(k!=-1) a.push_back({stoll(s.substr(0,k)),stoll(s.substr(k+1))});
        else break;
    }
    sort(a.begin(),a.end());
    int l=-1,r=-2;
    for(int i=0; i<a.size(); i++){
        if(a[i].first>r){
            ans+=r-l+1;
            l=a[i].first;
            r=a[i].second;
        }
        else r=max(r,a[i].second);
    }
    cout<<ans+r-l+1<<'\n';
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
/*

*/