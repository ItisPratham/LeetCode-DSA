/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void helper(Node* root, vector<int> &sol){
        if(!root){
            return;
        }
        else{
            sol.push_back(root->val);
            for(int i = 0; i<root->children.size(); i++){
                helper(root->children[i], sol);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> sol;
        helper(root, sol);
        return sol;
    }
};