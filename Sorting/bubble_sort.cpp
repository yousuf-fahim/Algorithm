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
    v = {4,9,22,-5,2,76,34,232,0,-1};

    cout<<"befor sort: "<<'\n';
    print(v);

    // bubble sort(O^2) start
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);
        }
    }
    // end

    cout<<"after sort: "<<'\n';
    print(v);
    return 0;
}

