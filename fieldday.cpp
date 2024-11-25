#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    int c,n; cin >> c >> n;

    vector<int> team(n);
    vector<int> dist((1LL<< (c+1)), 1000);
    queue<int> pq;

    for(int i=0; i<n; i++){
        string s; cin >> s;

        int nmr =0, inv = 0;

        for(auto j: s){

            nmr = nmr*2 + (j == 'G');
            inv = inv*2 + (j == 'H');
        }

        dist[inv] = 0;
        team[i] = nmr;
        pq.push(inv);
    }


    while(!pq.empty()){

        int x = pq.front(); pq.pop();
        

        for(int i = 0; i< c; i++){

            int novo = x ^ (1LL << i);
            if(dist[novo] <= dist[x] + 1) continue;
            dist[novo] = dist[x] + 1;
            pq.push(novo);
        }
    }

    for(auto i: team){
        cout << c- dist[i] << endl;
    }
}
