#include<bits/stdc++.h>
using namespace std;

int n = 10;
vector<int > v(n),temp(n);

void print(vector<int> v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<'\n';
}

// merge sort(nlogn)
void merge_sort(int st,int en){

    //divide
    if(st==en) return;
    int mid = (st+en) / 2;
    merge_sort(st,mid);
    merge_sort(mid+1,en);

    //conquer
    int li = st;
    int ri = mid+1;

    for(int i = st;i <= en;i++){
        if(v[li]<=v[ri]){
            temp[i] = v[li++];
        }else{
            temp[i] = v[ri++];
        }

        if(li ==mid+1 and i!=en){
            for(int j = i+1;j<=en;j++){
                temp[j] = v[ri++];
            }
            break;
        }else if(ri==en+1 and i!=en){
            for(int j = i+1;j<=en;j++){
                temp[j] = v[li++];
            }
            break;
        }
    }

    for(int i = st;i <= en; i++)    v[i] = temp[i];
}

int main(){

    v = {4,9,22,-5,2,76,34,232,0,-1};
    cout<<"befor sort: "<<'\n';
    print(v);

    merge_sort(0,n-1);

    cout<<"after sort: "<<'\n';
    print(v);
    return 0;
}

