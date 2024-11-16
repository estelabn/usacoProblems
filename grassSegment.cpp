#include <bits/stdc++.h>
using namespace std;

struct grass{
    int l,r,k,sz,idx;

    grass(){}
    grass(int x, int y, int z, int id){
        l = x; r = y; k = z; sz = y-x;
        idx = id;
    }
};

bool cmp1(grass a, grass b){
    return a.sz > b.sz;
}

bool cmp2(grass a, grass b){
    return a.k > b.k;
}

vector<int> treeR, treeL;
void addR(int pos, int i, int f, int idxx){

    if(i == f and i == idxx){
        treeR[pos] ++;
        return;
    }
    int meio = (i+f)/2;

    if(idxx <= meio) addR(2*pos+1, i, meio, idxx);
    else addR(2*pos+2, meio + 1, f, idxx);

    treeR[pos] = treeR[2*pos+1] + treeR[2*pos+2];
    return;
}

void addL(int pos, int i, int f, int idxx){

    if(i == f and i == idxx){
        treeL[pos]++;
        return;
    }
    int meio =(i+f)/2;
    if(idxx <= meio) addL(2*pos+1, i,meio, idxx);
    else addL(2*pos+2, meio +1, f, idxx);
    treeL[pos] = treeL[2*pos+1] + treeL[2*pos+2];
    return;
}

int answerR(int pos, int i, int f, int ll, int rr){

    if(ll<=i and f<= rr) return treeR[pos];
    int meio = (i+f)/2;

    int ssum = 0;

    if(ll <= meio) ssum += answerR(2*pos+1, i, meio, ll, rr);
    if(rr > meio) ssum += answerR(2*pos+2, meio +1, f, ll, rr);
    return ssum;
}

int answerL(int pos, int i, int f, int ll, int rr){
    if(ll <=i and f <= rr) return treeL[pos];

    int meio = (i+f)/2;

    int ssum = 0;

    if(ll <=meio) ssum += answerL(2*pos+1, i, meio, ll, rr);
    if(rr > meio) ssum += answerL(2*pos+2, meio+1, f,ll, rr);
    return ssum;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<grass> v(n);
    vector<int> aux;

    for(int i=0; i<n; i++){
        int l,r,k; cin >> l >> r >> k;
        aux.push_back(l); aux.push_back(r);
        v[i] = grass(l,r,k,i);
    }
    sort(aux.begin(), aux.end());
    vector<grass> query = v;
    sort(v.begin(), v.end(), cmp1);
    sort(query.begin(), query.end(), cmp2);

    int cont = 1;
    map<int,int> comp;

    for(auto i: aux){
        if(comp[i] == 0) {comp[i] = cont; cont++;}
    }

    treeL.assign(4*cont, 0); treeR.assign(4*cont, 0);

    int pont = 0;

    int sum = 0;
    vector<int> res(n);

    for(auto i: query){

        while(pont < n and v[pont].sz >= i.k){
            sum += 1;
            addR(0,0,cont,comp[v[pont].l]);
            addL(0,0,cont, comp[v[pont].r]);
            pont++;
        }

        int RR = i.r - i.k;
        auto RRR = upper_bound(aux.begin(), aux.end(), RR);
        int LL = i.l + i.k;
        auto LLL = lower_bound(aux.begin(), aux.end(), LL);

        res[i.idx] = sum-1;

        if(RRR != aux.end()){
            res[i.idx] -= answerR(0,0,cont,comp[*RRR], cont);
        }
        if(LLL != aux.begin()){
            res[i.idx] -= answerL(0,0,cont, 0, comp[*prev(LLL)]);
        }
    }

   for(auto i: res) cout << i << endl;

}
