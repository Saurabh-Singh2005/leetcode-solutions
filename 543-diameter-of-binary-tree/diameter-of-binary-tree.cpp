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
public:
    int height(TreeNode*root){
        if(root == NULL)  return 0;
       int  lefthei = height(root->left);
       int righthei = height(root->right);
        return max(lefthei,righthei)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      if(root == NULL) return 0;
      int leftdiam=diameterOfBinaryTree(root->left);
     int  rightdiam=diameterOfBinaryTree(root->right);
      int currdiam=height(root->left) +  height(root->right);
      return max(leftdiam,max(rightdiam,currdiam));
          }
};