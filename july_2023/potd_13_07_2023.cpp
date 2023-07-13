#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    bool iscycle(unordered_map<int,vector<int>>&adjlist,vector<int> &visited,int i){
        if(visited[i]==1)
            return true;
        if(visited[i]==0){
            visited[i]=1;
            for(auto edge : adjlist[i]){
                if(iscycle(adjlist,visited,edge))
                    return true;
            }
        }
        visited[i] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Create AdjList
        unordered_map<int,vector<int>> adjlist;
        for(auto edge : pre){
            int u= edge[0]; int v= edge[1];
            adjlist[v].push_back(u);
        }    
        vector<int> visited(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adjlist,visited,i))
                return false;
        }
        return true;
    }
};