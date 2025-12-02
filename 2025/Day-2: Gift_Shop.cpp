#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;cin>>s;
    s+=',';
    vector<pair<int,int>> a;
    auto clean_data=[&](){
        vector<string> b;
        string t;
        for(char c:s){
            if(c==','){
                t+='-';
                b.push_back(t);
                t.clear();
            }
            else t+=c;
        }
        for(auto &i:b){
            int l=-1,r;
            for(char c:i){
                if(c=='-'){
                    if(l==-1) l=stoll(t);
                    else r=stoll(t);
                    t.clear();
                }
                else t+=c;
            }
            a.push_back({l,r});
        }
        // for(auto &[x,y]:a) cout<<x<<' '<<y<<'\n';
    };
    clean_data();
    /*
    PART - 1:
        int ans=0;
        for(auto &[x,y]:a){
            for(int i=x; i<=y; i++){
                s=to_string(i);
                int m=s.size();
                if(m&1) continue;
                m>>=1;
                if(s.substr(0,m)==s.substr(m)) ans+=stoll(s);
            }
        }
        cout<<ans<<'\n';
    */
    // PART - 2:
    set<int> st;
    for(auto &[x,y]:a){
        for(int i=x; i<=y; i++){
            s=to_string(i);
            int m=s.size();
            for(int k=1; k<=m/2; k++){
                string t;
                while(t.size()<m) t+=s.substr(0,k);
                if(t==s) st.insert(i);
            }
        }
    }
    int ans=0;
    for(int i:st) ans+=i;
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