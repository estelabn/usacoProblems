#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxn = 5e6 + 10;

signed main(){

    freopen("teamwork.in", "r", stdin);

	freopen("teamwork.out", "w", stdout);

    int n,k; cin >> n >> k;

    vector<int> v(n+2);

    for(int i=1; i<=n; i++) cin >> v[i];

    vector<int> dp(n+2, 0);

    for(int i=1; i<=n; i++){

        int maior = 0, cont = 0;

        for(int j = i; j>max((int)0, i-k); j--){

            maior = max(maior, v[j]); cont++;

            dp[i] = max(dp[i], dp[j-1] + maior*cont);
        }

        //cout << i << " "<< dp[i] << endl;
    }

    cout << dp[n] << endl;
}
