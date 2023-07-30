#include <bits/stdc++.h>
using namespace std;

// find the longest sub-sequence of string P in string S
// Time complexity O(NM)
int longest_subsequence(string S, string P){

    int len_S = S.size();
    int len_P = P.size();

    int dp[len_P+1][len_S+1];
    memset(dp,0,sizeof dp);

    S = " "+S;
    P = " "+P;

    for(int i = 1; i < P.size(); i++){
        for(int j = 1; j < S.size(); j++){
            if(P[i] == S[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return dp[len_P][len_S];

}


int main(){
    string S = "abhgdc";
    string P = "abcdc";


    int lcs = longest_subsequence(S,P);

    cout<<"Length of LCS : "<<lcs<<endl;

}
