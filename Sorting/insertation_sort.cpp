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

    // insertion sort(O^2) start
    for(int i = 1;i<n;i++){
        int j = i;
        int cur = v[i];
        while(j-1>=0 and v[j-1]>cur){
            v[j] = v[j-1];
            j--;
        }
        v[j] =cur;
    }
    // end

    cout<<"after sort: "<<'\n';
    print(v);
    return 0;
}
