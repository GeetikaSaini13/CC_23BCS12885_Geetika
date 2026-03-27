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
    // calculate indegree

    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            indegree[it]++;
        }
    }
    //Push nodes with indegree 0 in queue
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //getting the values
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }

    }
     for(auto it:ans){
        cout<<it<<endl;
     }
    return 0;
    }