/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int matchingNodeCount = 0;

   
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

       
        auto [leftSum, leftCount] = postOrder(root->left);
        auto [rightSum, rightCount] = postOrder(root->right);

        int currentSum = leftSum + rightSum + root->val;
        int currentCount = leftCount + rightCount + 1;

      
        if (currentSum / currentCount == root->val) {
            matchingNodeCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return matchingNodeCount;
    }
};