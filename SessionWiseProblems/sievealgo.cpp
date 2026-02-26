#include<bits/stdc++.h>
using namespace std;
int main(){
//Finding primes
int n;
cin>>n;
//making all values till n as 0
//precomputation
vector<int>v(n+1,1);
v[0]=0;
v[1]=0;
for(int i=2;i<=sqrt(n);i++){
    //make all the multiples of 2 as 0
    if(v[i]==1){
    for(int j=i*i;j<=n;j+=i){
        v[j]=0;
    }}
}
//returning the all the primes

for(int i=0;i<=n;i++){
    if(v[i]==1)cout<<i<<" ";
}
return 0;
}