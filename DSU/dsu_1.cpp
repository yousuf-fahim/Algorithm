#include<bits/stdc++.h>
using namespace std;

struct DisjointSet{

    int total_set;
    int *Rank;
    int *parent;

    DisjointSet(int n){
        total_set = n;
        parent = new int[total_set+1];
        Rank = new int[total_set+1];
        make_set();
    }

    void make_set(){
        for(int i = 0; i<=total_set; i++){
            parent[i] = i;
            Rank[i] = 0;
        }
    }

    int find_parent(int x){
        if(x==parent[x])
            return x;
        else
            parent[x] = find_parent(parent[x]);

        return parent[x];
    }

    void Union(int A,int B){
        int parent_A = find_parent(A);
        int parent_B = find_parent(B);
        if(parent_A == parent_B) return;

        if(Rank[parent_A]>Rank[parent_B]){
            parent[parent_B] = parent_A;
        }else if(Rank[parent_A]<Rank[parent_B]){
            parent[parent_A] = parent_B;
        }else{
            parent[parent_B] = parent_A;
            Rank[parent_A]++;
        }
        return;
    }
};

int main(){

    DisjointSet djs(6);

    djs.Union(1,3);
    djs.Union(2,5);
    djs.Union(4,1);

    for(int i = 1; i<=6;i++){
        cout<<i<<" "<<djs.find_parent(i)<<endl;

    }

    return 0;
}
