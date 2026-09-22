#include <vector>

using namespace std;

struct Node {
    long long prod = 1;
    long long cnt[5] = {0};
};

class Solution {
private:
    int N;
    int K;
    vector<Node> tree;

    void combine(Node& res, const Node& left, const Node& right) {
        res.prod = (left.prod * right.prod) % K;
        for (int r = 0; r < K; ++r) {
            res.cnt[r] = left.cnt[r];
        }
        for (int r = 0; r < K; ++r) {
            int new_r = (left.prod * r) % K;
            res.cnt[new_r] += right.cnt[r];
        }
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            for (int r = 0; r < K; ++r) tree[node].cnt[r] = 0;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        combine(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            tree[node].prod = rem;
            for (int r = 0; r < K; ++r) tree[node].cnt[r] = 0;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        combine(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        Node res;
        combine(res, left, right);
        return res;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        N = nums.size();
        K = k;
        tree.resize(4 * N);

        build(1, 0, N - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, N - 1, idx, val);

            Node resNode = query(1, 0, N - 1, start, N - 1);
            ans.push_back((int)resNode.cnt[x]);
        }

        return ans;
    }
};