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

 // root -> leaf 
 // dfs 
 // traverse in the order of node -> left -> right  
 // while iterating, count up the length 
 //    if it's a leaf node -> update the max path len
 // -> algo - temporal:O(logN), spatial:O(N) 
 // recursive function - curNode, curLen (return: curMax)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int curLen){
        if(node == NULL){
            return curLen;
        }
        
        return max(dfs(node->left, curLen+1), dfs(node->right, curLen+1));
    }
};





