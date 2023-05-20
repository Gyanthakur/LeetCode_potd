#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> results;

        for (const auto& query : queries) {
            const string& dividend = query[0];
            const string& divisor = query[1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()) {
                results.push_back(-1.0);
            } else {
                results.push_back(bfs(dividend, divisor, graph));
            }
        }

        return results;
    }

private:
    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            const string& dividend = equations[i][0];
            const string& divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        return graph;
    }

    double bfs(const string& start, const string& end, unordered_map<string, unordered_map<string, double>>& graph) {
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({start, 1.0});

        while (!q.empty()) {
            string node = q.front().first;
            double value = q.front().second;
            q.pop();

            if (node == end) {
                return value;
            }

            visited.insert(node);

            for (const auto& neighbor : graph[node]) {
                const string& neighborNode = neighbor.first;
                double neighborValue = neighbor.second;

                if (visited.find(neighborNode) == visited.end()) {
                    q.push({neighborNode, value * neighborValue});
                }
            }
        }

        return -1.0;
    }
};