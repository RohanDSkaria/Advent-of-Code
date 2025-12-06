#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<string> a;
    string s;
    while(cin>>s) a.push_back(s);
    int n=a.size(),m=a[0].size(),ans=0;
    vector<int> dx={-1,-1,0,1,1,1,0,-1};
    vector<int> dy={0,-1,-1,-1,0,1,1,1};
    // PART - 1:
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(a[i][j]=='.') continue;
    //         int c=0;
    //         for(int d=0; d<8; d++){
    //             int x=i+dx[d],y=j+dy[d];
    //             if(x<n && x>=0 && y<m && y>=0 && a[x][y]=='@') c++;
    //         }
    //         ans+=c<4;
    //     }
    // }
    // cout<<ans<<'\n';
    // PART - 2:
    vector<vector<int>> adj(n,vector<int>(m)),vis=adj;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='.') continue;
            for(int d=0; d<8; d++){
                int x=i+dx[d],y=j+dy[d];
                if(x<n && x>=0 && y<m && y>=0 && a[x][y]=='@') adj[i][j]++;
            }
            if(adj[i][j]<4){
                q.push({i,j});
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        ans++;
        for(int d=0; d<8; d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<n && nx>=0 && ny<m && ny>=0 && !vis[nx][ny] && a[nx][ny]=='@'){
                if(--adj[nx][ny]<4){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
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