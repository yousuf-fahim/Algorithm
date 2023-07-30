#include<bits/stdc++.h>
using namespace std;

const int mx = 1000000;
bool notPrime[mx+2];

void sieve(int n,vector<int> &primes){
    notPrime[0]=1;
    notPrime[1]=1;
    primes.push_back(2);

    for(int i=4;i<=n;i+=2){
        notPrime[i]=1;
    }
    for(int i=3;i<=(int)sqrt(n);i+=2){
        if(notPrime[i]==0){
            primes.push_back(i);
            for(int j=i+i;j<=n;j+=i){
                notPrime[j]=1;
            }
        }
    }
    for(int i = sqrt(n)+1; i <= n; i++) if(notPrime[i]==false) primes.push_back(i);
}


int main(){

    int n;
    cin>> n;

    vector<int > primes;
    sieve(n,primes);

    for(int i = 0; i < primes.size(); i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl<<"Total : "<<primes.size()<<endl;

    return 0;
}
