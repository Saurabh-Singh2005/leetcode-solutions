class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<unordered_map<int, int>> dist(n);
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;

        pq.push({0, 0, 1, labels[0]});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto [w, u, count, last_char] = pq.top();
            pq.pop();

            if (u == n - 1) return w;

            if (dist[u].count(count) && dist[u][count] < w) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                char next_char = labels[v];

                int next_count = (next_char == last_char) ? count + 1 : 1;

                if (next_count > k) continue;

                int next_w = w + weight;

                if (!dist[v].count(next_count) || next_w < dist[v][next_count]) {
                    dist[v][next_count] = next_w;
                    pq.push({next_w, v, next_count, next_char});
                }
            }
        }

        return -1;
    }
};