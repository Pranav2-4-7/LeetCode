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
private: 
    int global_max = 0;
public:
    int maxPathSum(TreeNode* root) {
        global_max = INT_MIN;
        calculateMaxBranch(root);
        return global_max;
    }

private:
    int calculateMaxBranch(TreeNode* root){
        if(root == nullptr) return 0;

        int right = max(calculateMaxBranch(root->right) , 0);
        int left = max(calculateMaxBranch(root->left) , 0);
        int currentsum = root->val + right + left;
        if(currentsum > global_max){
            global_max = currentsum;
        }
        return root->val + max(left , right);
    }
};