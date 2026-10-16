class Solution {
    typedef long long ll;
    int MOD = 1e9 + 7;
    int n;
    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r, ll val) {
        ll len = (r - l + 1);
        sqSumSegTree[i] = (sqSumSegTree[i] + 2 * val % MOD * sumSegTree[i] + len * (val * val % MOD) % MOD) % MOD;
        sumSegTree[i] = (sumSegTree[i] + (len * val) % MOD) % MOD;
    }

    void updateRange(int start, int end, int i, int l, int r, ll val) {
        if (start > r || end < l) return;
        if (start <= l && r <= end) {
            lazyAddition(i, l, r, val);
            lazyTree[i] = (lazyTree[i] + val) % MOD;
            return;
        }
        if (lazyTree[i] != 0) {
            int mid = l + (r - l) / 2;
            lazyAddition(2 * i + 1, l, mid, lazyTree[i]);
            lazyTree[2 * i + 1] = (lazyTree[2 * i + 1] + lazyTree[i]) % MOD;
            
            lazyAddition(2 * i + 2, mid + 1, r, lazyTree[i]);
            lazyTree[2 * i + 2] = (lazyTree[2 * i + 2] + lazyTree[i]) % MOD;
            
            lazyTree[i] = 0;
        }
        int mid = l + (r - l) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);
        
        sumSegTree[i] = (sumSegTree[2 * i + 1] + sumSegTree[2 * i + 2]) % MOD;
        sqSumSegTree[i] = (sqSumSegTree[2 * i + 1] + sqSumSegTree[2 * i + 2]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sqSumSegTree.assign(4 * n, 0);
        sumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);
        
        vector<int> lastSeenIdx(100005, -1);
        ll result = 0;
        for (int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end = i;
            updateRange(start, end, 0, 0, n - 1, 1);
            result = (result + sqSumSegTree[0]) % MOD;
            lastSeenIdx[nums[i]] = i;
        }
        return result;
    }
};