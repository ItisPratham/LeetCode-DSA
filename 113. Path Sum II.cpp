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
    void findPaths(TreeNode* root, int targetSum, vector<int>& current, vector<vector<int>>& result){
        if(!root){
            return;
        }
        current.push_back(root->val);
        targetSum -= root->val;

        if(targetSum == 0 && !root->left && !root->right){
            result.push_back(current);
        }
        else{
            findPaths(root->left, targetSum, current, result);
            findPaths(root->right, targetSum, current, result);
        }
        current.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> current;
        findPaths(root, targetSum, current, result);
        return result;
    }
};