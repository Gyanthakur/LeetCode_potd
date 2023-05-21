#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}



class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        // Step 1: Find the first island using DFS and mark its cells as visited
        bool found = false;
        unordered_set<int> visited;
        for (int i = 0; i < m; i++) {
            if (found) {
                break;
            }
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, visited);
                    found = true;
                    break;
                }
            }
        }

        // Step 2: Perform BFS to find the shortest bridge to the second island
        queue<int> q;
        for (int cell : visited) {
            q.push(cell);
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                int currI = curr / n;
                int currJ = curr % n;

                for (auto dir : directions) {
                    int ni = currI + dir[0];
                    int nj = currJ + dir[1];
                    int neighbor = ni * n + nj;

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited.find(neighbor) == visited.end()) {
                        if (A[ni][nj] == 1) {
                            return level;
                        }
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            level++;
        }

        return -1; // No bridge found
    }

private:
    void dfs(vector<vector<int>>& A, int i, int j, unordered_set<int>& visited) {
        int m = A.size();
        int n = A[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1 || visited.find(i * n + j) != visited.end()) {
            return;
        }

        visited.insert(i * n + j);
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(A, ni, nj, visited);
        }
    }
};