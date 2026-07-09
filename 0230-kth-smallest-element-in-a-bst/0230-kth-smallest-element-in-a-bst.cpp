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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted_element;
        inorder(root, sorted_element);

        return sorted_element[k-1];
    }
private: 
    void inorder(TreeNode* node, vector<int>& elements){
        if(node == nullptr) return; 

        inorder(node->left, elements);
        elements.push_back(node->val);

        inorder(node->right, elements);


    }
};