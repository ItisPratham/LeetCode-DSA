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
    int checkBalance(TreeNode* root){
        if(!root){
            return 0;
        }

        int lheight = checkBalance(root->left);
        int rheight = checkBalance(root->right);
        if(lheight == -1 || rheight == -1 || abs(lheight - rheight) > 1){
            return -1;
        }

        return 1 + max(lheight, rheight);

    }
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};