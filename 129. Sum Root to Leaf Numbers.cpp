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
    void findPaths(TreeNode* root, int& sum, int current){
        if(!root){
            return;
        }

        current = current*10 + root->val;

        if(!root->left && !root->right){
            sum += current;
        }
        else{
            findPaths(root->left, sum, current);
            findPaths(root->right, sum, current);
        }

        current = 0;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, current = 0;
        findPaths(root, sum, current);
        return sum;
    }
};