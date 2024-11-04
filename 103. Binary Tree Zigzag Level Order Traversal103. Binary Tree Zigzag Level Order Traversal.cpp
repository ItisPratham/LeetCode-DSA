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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelData(levelSize);

            for(int i = 0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if(flag){
                    levelData[i] = node->val;
                }
                else{
                    levelData[levelSize-i-1] = node->val;
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(levelData);
            flag = !flag;
        }
        return ans;
    }
};