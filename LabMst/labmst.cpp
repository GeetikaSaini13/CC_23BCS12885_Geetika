#include<bits/stdc++.h>
using namespace std;
int singleNum(vector<int>v){
    int ones=0;
    int twos=0;
    for(auto num:v){
        ones=(ones^num)& ~twos;
        twos=(twos^num)& ~ones;
    }
    return ones;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    //inserting array
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"single number is "<<singleNum(v);
   

}