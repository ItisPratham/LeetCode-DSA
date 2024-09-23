class Solution {
public:
    bool isValid(string s) {
        stack<char> vp;
        map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        for(char c : s){
            if(m.count(c)){
                vp.push(c);
            }
            else{
                if(vp.empty() || m[vp.top()] != c){
                    return false;
                }
                vp.pop();
            }
        }
        return vp.empty();
    }
};