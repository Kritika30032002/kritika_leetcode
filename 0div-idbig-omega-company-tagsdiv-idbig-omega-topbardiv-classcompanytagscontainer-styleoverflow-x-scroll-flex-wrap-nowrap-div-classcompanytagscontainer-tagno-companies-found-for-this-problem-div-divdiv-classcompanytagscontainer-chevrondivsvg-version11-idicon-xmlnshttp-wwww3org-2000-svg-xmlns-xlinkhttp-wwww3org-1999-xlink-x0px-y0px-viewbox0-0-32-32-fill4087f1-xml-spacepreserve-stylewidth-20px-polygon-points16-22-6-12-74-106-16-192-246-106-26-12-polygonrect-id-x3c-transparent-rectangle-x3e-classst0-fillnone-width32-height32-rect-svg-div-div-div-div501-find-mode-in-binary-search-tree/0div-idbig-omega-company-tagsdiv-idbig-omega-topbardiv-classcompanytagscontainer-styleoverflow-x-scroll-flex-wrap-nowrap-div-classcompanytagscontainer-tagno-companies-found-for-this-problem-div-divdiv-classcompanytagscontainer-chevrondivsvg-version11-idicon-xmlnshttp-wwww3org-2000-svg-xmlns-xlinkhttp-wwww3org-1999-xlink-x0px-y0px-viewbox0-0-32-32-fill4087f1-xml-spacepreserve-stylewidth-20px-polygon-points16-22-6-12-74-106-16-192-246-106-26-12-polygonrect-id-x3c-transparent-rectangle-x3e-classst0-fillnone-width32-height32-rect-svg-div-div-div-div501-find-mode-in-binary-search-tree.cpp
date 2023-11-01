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
//Approach-1 (Using O(n) space)
//T.C : O(n)
//S.C : O(n)
// class Solution {
// public:
//     unordered_map<int, int> mp;
    
//     void dfs(TreeNode* root) {
//         if(!root)
//             return;
        
//         dfs(root->left);
//         mp[root->val]++;
//         dfs(root->right);
//     }
    
//     vector<int> findMode(TreeNode* root) {
//         dfs(root);
        
//         vector<int> result;
//         int maxFreq = 0;
        
//         for(auto &it : mp) {
//             if(it.second > maxFreq) {
//                 maxFreq = it.second;
//                 result = {};
//                 result.push_back(it.first);
//             } else if (it.second == maxFreq) {
//                 result.push_back(it.first);
//             }
//         }
        
//         return result;
        
//     }
// };


//Approach-2 (without Using extra space)
//T.C : O(n)
//S.C : O(1) (stack space is not considered)
class Solution {
public:
    int currNum    = 0;
    int currfreq = 0;
    int maxfreq  = 0;
    vector<int> result;
    
    void inorder(TreeNode* root) {
        if(!root)
            return;
        
        inorder(root->left);
        
        if(root->val == currNum) {
            currfreq++;
        } else {
            currNum    = root->val;
            currfreq = 1;
        }
        
        if(currfreq > maxfreq) {
            result = {};
            maxfreq = currfreq;
        }
        
        if(currfreq == maxfreq) {
            result.push_back(root->val);
        }
        
        inorder(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        
        return result;
    }
};