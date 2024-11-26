#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxn = 5e6 + 10;

signed main(){

    freopen("time.in", "r", stdin);

	freopen("time.out", "w", stdout);

    int n,m,c; cin >> n >> m >> c;

    vector<vector<int>> adj(n+2);
    vector<int> v(n+3);

    vector<vector<int>> dp(n+3, vector<int> (1100, -1));

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    dp[1][0] = 0;

    int res =0;

    for(int day = 0; day<1100-1; day++) for(int i = 1; i<=n; i++){

        if(dp[i][day] == -1) continue;
        // cout << "day "<< day << " i "<< i << " "<< dp[i][day] << endl;

        if(i == 1) res = max(res, dp[i][day] - c*day*day);

        for(auto j: adj[i]){
            dp[j][day+1] = max(dp[j][day+1], dp[i][day] + v[j]);
        }
    }
    cout << res << endl;
}
