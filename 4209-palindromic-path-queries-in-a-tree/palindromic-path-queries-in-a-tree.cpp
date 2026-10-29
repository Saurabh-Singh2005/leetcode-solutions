#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    int n_nodes;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> tree;
    string node_chars;
    int cur_pos;

   
    int dfs1(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        int size = 1, max_sub_size = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int sub_size = dfs1(v, u, d + 1);
                size += sub_size;
                if (sub_size > max_sub_size) {
                    max_sub_size = sub_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    
    void update_tree(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) update_tree(2 * node, l, mid, idx, val);
        else update_tree(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        return query_tree(2 * node, l, mid, ql, qr) ^ query_tree(2 * node + 1, mid + 1, r, ql, qr);
    }

    
    int query_path(int u, int v) {
        int res_xor = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res_xor ^= query_tree(1, 0, n_nodes - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res_xor ^= query_tree(1, 0, n_nodes - 1, pos[u], pos[v]);
        return res_xor;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n_nodes = n;
        node_chars = s;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree.assign(4 * n, 0);
        cur_pos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

       
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (node_chars[i] - 'a');
            update_tree(1, 0, n_nodes - 1, pos[i], mask);
        }

        vector<bool> answer;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                node_chars[u] = c;
                int mask = 1 << (c - 'a');
                update_tree(1, 0, n_nodes - 1, pos[u], mask);
            } else {
                int u, v;
                ss >> u >> v;
                int path_mask = query_path(u, v);
               
                bool is_palindrome = (path_mask == 0) || ((path_mask & (path_mask - 1)) == 0);
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};