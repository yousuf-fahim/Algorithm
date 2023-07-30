#include<bits/stdc++.h>
using namespace std;

int n = 10;
vector<int > v(n);

void print(vector<int> v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<'\n';
}

int Partition(int st,int en){
    int pivot_element = v[en];
    int small_index = st;

    for(int i = st; i<=en; i++){
        if(v[i]<pivot_element){
            swap(v[i],v[small_index]);
            small_index++;
        }
    }
    swap(v[small_index],v[en]);
    return small_index;
}

// quick sort(nlogn)
void quick_sort(int st,int en){
    if(st>=en) return;
    int pivot = Partition(st,en);
    quick_sort(st,pivot-1);
    quick_sort(pivot+1,en);
}


int main(){

    v = {4,9,22,-5,2,76,34,232,0,-1};

    cout<<"befor sort: "<<'\n';
    print(v);

    quick_sort(0,n-1);

    cout<<"after sort: "<<'\n';
    print(v);
    return 0;
}

