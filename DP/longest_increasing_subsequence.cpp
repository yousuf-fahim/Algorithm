#include<bits/stdc++.h>
using namespace std;


void lis(vector<int> D){

    vector<int> L[D.size()];

    L[0].push_back(D[0]);

    for(int i = 1; i<D.size();i++){
        for(int j=0;j<i;j++){
            if(D[j]<D[i]){
                if(L[i].size()<L[j].size()+1){
                    L[i] = L[j];
                }
            }
        }

        L[i].push_back(D[i]);
    }

    for(auto x:L){
        for(auto i:x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}



int main(){

    vector<int> v;
    cout<<"Enter number of integer"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    lis(v);
}
