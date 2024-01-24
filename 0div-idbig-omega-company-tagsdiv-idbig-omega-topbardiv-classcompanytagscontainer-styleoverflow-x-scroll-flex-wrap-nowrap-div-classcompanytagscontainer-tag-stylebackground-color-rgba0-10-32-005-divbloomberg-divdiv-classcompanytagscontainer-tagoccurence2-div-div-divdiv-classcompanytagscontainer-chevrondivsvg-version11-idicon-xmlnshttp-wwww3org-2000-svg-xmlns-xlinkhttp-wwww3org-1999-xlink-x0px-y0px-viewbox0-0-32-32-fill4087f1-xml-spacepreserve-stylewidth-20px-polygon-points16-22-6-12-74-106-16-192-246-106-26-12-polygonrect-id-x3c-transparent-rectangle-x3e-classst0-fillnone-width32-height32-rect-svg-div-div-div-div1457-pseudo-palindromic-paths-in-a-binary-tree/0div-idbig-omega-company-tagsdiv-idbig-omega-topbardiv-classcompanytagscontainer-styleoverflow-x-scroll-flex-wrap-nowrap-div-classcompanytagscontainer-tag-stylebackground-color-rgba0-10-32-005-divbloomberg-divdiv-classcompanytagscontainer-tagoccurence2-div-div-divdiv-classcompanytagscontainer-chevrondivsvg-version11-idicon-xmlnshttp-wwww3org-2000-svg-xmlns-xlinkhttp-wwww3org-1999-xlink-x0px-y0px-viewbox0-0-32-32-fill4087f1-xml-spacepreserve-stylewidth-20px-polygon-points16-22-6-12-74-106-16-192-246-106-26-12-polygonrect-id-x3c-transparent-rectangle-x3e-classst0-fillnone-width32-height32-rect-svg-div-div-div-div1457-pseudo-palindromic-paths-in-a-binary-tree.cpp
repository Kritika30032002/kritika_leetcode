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
   int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};