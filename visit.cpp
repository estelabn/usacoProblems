#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
int n,m,k;

signed main(){

    freopen("cruise.in", "r", stdin); 
  freopen("cruise.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    vector<vector<int>>pulo(n+2, vector<int> (31, 0));
    vector<ii> prox(n+2);

    for(int i=1; i<=n; i++) cin >> prox[i].first >> prox[i].second;

    vector<int> ordem(m+2);

    for(int i=0; i<m; i++){
        char c; cin >> c;
        if(c == 'L') ordem[i] = 0;
        else ordem[i] = 1;
    }


    for(int i=1; i<=n;i++){
        int atual = i;

        for(int j=0; j<m; j++){
            if(ordem[j] == 0) atual = prox[atual].first;
            else atual = prox[atual].second;
        }
        pulo[i][0] = atual;
    }

    for(int i=1; i<31; i++) for(int j = 1; j<=n; j++){
        pulo[j][i] = pulo[pulo[j][i-1]][i-1];
    }

    int atual = 1;

    for(int i=30; i>=0; i--){
        if((1LL<<i) > k) continue;

        atual = pulo[atual][i];
        k -= (1LL<<i);
    }
    cout << atual << endl;
}
