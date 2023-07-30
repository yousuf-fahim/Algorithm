// prime number up to 10^12 with range L to R where R - L <= 1e6
// complexity O((R−L+1)loglog(R)+√Rloglog√R).
#include <bits/stdc++.h>
using namespace std;

void normal_sieve(int n,vector<int> &primes){
    bool composite[n+2] = {0};
    composite[0]=1;
    composite[1]=1;
    primes.push_back(2);

    for(int i=4;i<=n;i+=2){
        composite[i]=1;
    }
    for(int i=3;i<=(int)sqrt(n);i+=2){
        if(composite[i]==0){
            primes.push_back(i);
            for(int j=i+i;j<=n;j+=i){
                composite[j]=1;
            }
        }
    }
    for(int i = sqrt(n)+1; i <= n; i++) if(!composite[i]) primes.push_back(i);
}

void segment_sieve(long long low,long long high, vector<long long> &primes){

    low = max(low,2LL);

    int limit = sqrt(high) + 1;
    vector<int> p;
    normal_sieve(limit,p);

    int total = high - low + 1;
    bool composite[total + 1] = {0};

    for(int i = 0; i < p.size(); i++){
        long long small_multiple = (low / p[i]) * p[i];

        while(small_multiple<=p[i] or small_multiple<low) small_multiple += p[i];  //if(low % p[i]) small_mutiple += p[i]; if(small_mutiple<=p[i]) small_mutiple += p[i];

        for(long long j = small_multiple; j <= high; j+=p[i]){
            composite[j - low] = 1;
        }
    }
    for(long long i = low; i <= high; i++)   if(!composite[i - low])   primes.push_back(i);
}

int main(){

    long long low, high;
    cin>>low>>high;

    if(low > high or high - low > 1000000){
        cout<<"Invalid Input"<<endl;
        exit(0);
    }

    vector<long long> primes;

    segment_sieve(low,high,primes);

    for(int i = 0; i < primes.size(); i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl<<"Total : "<<primes.size()<<endl;

}
