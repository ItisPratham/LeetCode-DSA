/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelper(TreeNode* root, string &sol){
        if(!root){
            sol += "n ";
            return;
        }
        sol += to_string(root->val)+" ";
        serializeHelper(root->left, sol);
        serializeHelper(root->right, sol);
        return;
    }

    TreeNode* deserializeHelper(string &data, int &index){
        int next_index = data.find(" ", index);
        string sub = data.substr(index, next_index-index);
        index = next_index+1;
        if(sub == "n"){
            return NULL;
        }
        else{
            int val = stoi(sub);
            TreeNode* node = new TreeNode(val);
            node->left = deserializeHelper(data, index);
            node->right = deserializeHelper(data, index);
            return node;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string sol;
        serializeHelper(root, sol);
        return sol;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));