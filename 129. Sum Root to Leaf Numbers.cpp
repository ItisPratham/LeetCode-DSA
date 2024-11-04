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
    void findPaths(TreeNode* root, vector<vector<int>>& allPaths, vector<int>& currentPath){
        if(!root){
            return;
        }

        currentPath.push_back(root->val);

        if(!root->left && !root->right){
            allPaths.push_back(currentPath);
        }
        else{
            findPaths(root->left, allPaths, currentPath);
            findPaths(root->right, allPaths, currentPath);
        }

        currentPath.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findPaths(root, allPaths, currentPath);
        int sum = 0;

        for(vector<int> element : allPaths){
            int size = element.size();
            int temp = 0;
            for(int i = 0; i < size; i++){
                temp += element[i]*pow(10, size-i-1);
            }
            sum += temp;
        }

        return sum;
    }
};