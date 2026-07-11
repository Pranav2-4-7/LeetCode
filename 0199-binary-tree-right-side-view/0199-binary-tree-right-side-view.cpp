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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> right_node = rightSideView(root->right);
        vector<int> left_node = rightSideView(root->left);

        for(int i = right_node.size(); i < left_node.size(); i++){
            right_node.push_back(left_node[i]);
        }

        right_node.insert(right_node.begin() , root->val);

        return right_node;
    }
};