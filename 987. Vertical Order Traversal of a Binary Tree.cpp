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
    void vertical_traversal_table(map<int, map<int, vector<int>>>& hash, int row, int column, TreeNode* root){
        if(!root){
            return;
        }

        hash[column][row].push_back(root->val);

        vertical_traversal_table(hash, row+1, column-1, root->left);
        vertical_traversal_table(hash, row+1, column+1, root->right);    
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> hash;

        vertical_traversal_table(hash, 0, 0, root);
        vector<vector<int>> result;
        for(auto it = hash.begin(); it!= hash.end(); it++){
            vector<int> data;
            for(auto it2 = (it->second).begin(); it2 != (it->second).end(); it2++){
                sort(it2->second.begin(), it2->second.end());
                for(auto it3 = (it2->second).begin(); it3 != (it2->second).end(); it3++){
                    data.push_back(*it3);
                }
            }
            result.push_back(data);
        }
        return result;
    }
};