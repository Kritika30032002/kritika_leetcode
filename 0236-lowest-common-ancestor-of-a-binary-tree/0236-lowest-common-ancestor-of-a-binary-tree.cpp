/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lca = NULL;

pair<bool, bool> computeState(TreeNode *root, TreeNode *a, TreeNode *b)
{
    if (root == NULL)
        return {false, false};

    pair<bool, bool> leftAns = computeState(root->left, a, b);
    pair<bool, bool> rightAns = computeState(root->right, a, b);

    pair<bool, bool> rootAns = {
        leftAns.first | rightAns.first | root == a,
        leftAns.second | rightAns.second | root == b
    };

    if (rootAns == make_pair(true, true) && lca == NULL)
           lca = root;
    
    return rootAns;
     }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        computeState(root,p,q);
        return lca;
    }
};