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
    void helper(Node* root, int &sol, int &temp){
        if(!root){
            return;
        }
        if(temp > sol){
            sol = temp;
        }
        for(int i = 0; i<root->children.size(); i++){
            temp++;
            helper(root->children[i], sol, temp);
            temp--;
        }
    }
public:
    int maxDepth(Node* root) {
        int sol = 0;
        int temp = 1;
        if(!root){
            return sol;
        }
        helper(root, sol, temp);
        return sol;
    }
};