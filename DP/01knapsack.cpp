// given some weight and corresponding value
// we have to maximize the value without exceeding a certain weight
// every item is distinct

#include<bits/stdc++.h>
#define mx 10000
using namespace std;

int value[mx];
int dp[mx][mx];
vector<int> item;

void knapsack(int n,int weight){

    for(int i=0;i<item.size();i++){
        for(int j=1;j<=weight;j++){
            if(i==0){ // special treat for first item
                if(j>=item[i]){
                    dp[i][j] = j;
                }
            }else{
                if(j>=item[i]){
                    dp[i][j] = max(dp[i-1][j], value[item[i]] + dp[i-1][j-item[i]] );
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
}

void print_item(int r,int c){
    vector<int> res;
    while(r>0 and c>0){
        if(dp[r][c]!=dp[r-1][c]){
            res.push_back(item[r]);
            c-= item[r];
        }
        r--;
    }
    cout<<"Picked item : ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;

    for(int i = 0;i<n;i++){
        int w,v;
        cin>>w>>v;
        value[w] = v;
        item.push_back(w);
    }

    sort(item.begin(),item.end());

    int w;  // maximum weight
    cin>>w;

    knapsack(n,w);

    cout<<"Maximum value : "<<dp[n-1][w]<<endl;

    print_item(n-1,w);

    return 0;
}
/*
4
1 1
3 4
4 5
5 7
7
*/
