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
    vector<int> ret;
    void printSubtreeNodesAtDistanceK(TreeNode* ref, int k){
        if(ref==NULL) return;
        vector<TreeNode*> current, nxt;
        current.push_back(ref);
        int lvl = 0;
        while(current.size()){
            if(lvl==k){
                for(auto itr : current){
                    ret.push_back(itr->val);
                }
                break;
            }

            for(auto itr : current){
                if(itr->left!=NULL) nxt.push_back(itr->left);
                if(itr->right!=NULL) nxt.push_back(itr->right);
            }
            swap(current, nxt);
            nxt.clear();
            lvl++;
        }
    }

    int rec(TreeNode* currentNode, TreeNode* ref, int k){
        if(currentNode==NULL) return 1e9;
        if(currentNode==ref){
            printSubtreeNodesAtDistanceK(currentNode, k);
            return 0;
        }
        int lt = rec(currentNode->left, ref, k);
        int rt = rec(currentNode->right, ref, k);
        int meraDist = min(lt, rt)+1;
        if(lt<1e9) printSubtreeNodesAtDistanceK(currentNode->right, k-meraDist-1);
        if(rt<1e9) printSubtreeNodesAtDistanceK(currentNode->left, k-meraDist-1);
        if(meraDist==k){
            ret.push_back(currentNode->val);
        }
        return meraDist;
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ret.clear();
        rec(root, target, k);
        return ret;
    }
};