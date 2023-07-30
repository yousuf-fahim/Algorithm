
#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<'\n';
}

int main(){

    int n = 10;
    vector<int > v(n);
    v = {4,9,22,5,2,76,34,232,0,0};

    cout<<"befor sort: "<<'\n';
    print(v);

    // counting sort(N+n only for small non-negative numbers) start
    int Count[1000] = {0};
    int in = 0;
    for(int x:v) Count[x]++;
    for(int i =0;i<1000;i++){
        while(Count[i]){
            v[in++] = i;
            Count[i]--;
        }
    }
    // end

    cout<<"after sort: "<<'\n';
    print(v);
    return 0;
}

