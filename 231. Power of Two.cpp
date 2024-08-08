class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1){
            return false;
        }
        else{
            return (floor(log2(n)) == log2(n));
        }
    }
};