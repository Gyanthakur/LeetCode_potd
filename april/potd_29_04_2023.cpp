#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

class UnionFind
{
    vector<int> parent;

public:
    UnionFind(int n) : parent(n)
    {
        iota(begin(parent), end(parent), 0);
    }
    void connect(int a, int b)
    {
        int x = find(a), y = find(b);
        if (x == y)
            return;
        parent[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a)
    {
        return parent[a] == a ? a : (parent[a] = find(parent[a]));
    }
};

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);
        sort(begin(queries), end(queries), [&](auto &a, auto &b)
             { return a[2] < b[2]; });
        sort(begin(edges), end(edges), [&](auto &a, auto &b)
             { return a[2] < b[2]; });
        UnionFind uf(n);
        int i = 0;
        for (auto &q : queries)
        {
            int u = q[0], v = q[1], limit = q[2], qid = q[3];
            for (; i < edges.size() && edges[i][2] < limit; ++i)
                uf.connect(edges[i][0], edges[i][1]);
            ans[qid] = uf.connected(u, v);
        }
        return ans;
    }
};