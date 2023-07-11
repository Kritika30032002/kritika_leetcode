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
    int minDepth(TreeNode* root) {
       if(root==NULL)   return 0;
       int ldep=minDepth(root->left);
       int rdep=minDepth(root->right);
       if(ldep==0|| rdep==0) return(ldep+rdep+1);
       return min(ldep,rdep)+1; 
    }
};