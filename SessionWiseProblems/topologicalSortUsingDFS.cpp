#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>graph[6];
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[4].push_back(0);
    int n=6;
    vector<int>visited(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            
        }
    }
}