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
//T.C : O(n)
//S.C : O(1) (excluding recursion stack space)
class Solution {
public:
    int result;
    
    pair<int, int> solve(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        
        int leftSum   = l.first;
        int leftCount = l.second;
        
        int rightSum   = r.first;
        int rightCount = r.second;
        
        int SUM   = leftSum + rightSum + root->val;
        int COUNT = leftCount + rightCount + 1;
        
        int avg = SUM/COUNT;
        
        if(avg == root->val) {
            result++;
        }
        
        return {SUM, COUNT};
    }
    
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
};