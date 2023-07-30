#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();

    vector<int> cnt(n);
    for(int x: c){
        cnt[x]++;
    }

    vector<int> np(n);
    vector<int> pos(n);

    pos[0] = 0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }

    for(int x:p){
        int i = c[x];
        np[pos[i]++] = x;
    }
    p = np;

}

// suffix array
// complexity O(nlog n)
vector<int > p,c,lcp;

void build_suffix(string str,int len){
    p.resize(len);
    c.resize(len);
    // k = 0
    vector<pair<char,int>> v(len);
    for(int i = 0; i < len; i++)    v[i] = {str[i],i};
    sort(v.begin(),v.end());

    for(int i = 0; i < len; i++)    p[i] = v[i].second;

    c[p[0]] = 0;

    for(int i = 1; i< len; i++){
        int cur = v[i].first;
        int prv = v[i-1].first;
        if(cur == prv)  c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]] + 1;
    }

    // transition
    int k = 0;
    int cur_pow = pow(2,k);
    while(cur_pow < len){
        //k -> k + 1

        for(int i = 0; i < len; i++)    p[i] = (p[i] - cur_pow + len) % len;

        count_sort(p,c);

        vector<int > nc(len);

        nc[p[0]] = 0;

        for(int i = 1; i<len; i++){
            pair<int,int > cur = { c[p[i]], c[(p[i]+cur_pow) % len] };
            pair<int,int > prv = { c[p[i-1]], c[(p[i-1]+cur_pow) % len]};

            if(cur==prv){
                nc[p[i]] = nc[p[i-1]];
            }else{
                nc[p[i]] = nc[p[i-1]] + 1;
            }
        }
        c = nc;
        k++;
        cur_pow = pow(2,k);
    }
}

void calculate_lcp(string str, int len){
    lcp.resize(len);
    int k = 0;
    for(int i = 0; i < len - 1; i++){
        int pi = c[i];
        int j = p[pi - 1];
        while(str[i+k] == str[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1,0);
    }
}

int main(){

    string str;
    cin>>str;

    str = str + "$";
    int len = str.size();

    build_suffix(str,len);

    calculate_lcp(str,len);

    for(int i = 0; i<p.size(); i++){
        cout<<lcp[i]<<" "<<p[i]<<" "<<str.substr(p[i],len-p[i])<<endl;
    }
}
