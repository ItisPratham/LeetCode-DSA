class Solution {
public:
    int fib(int n) {
    int arr[n+2];
    memset(arr, -1, sizeof(arr));
    int i = 2;
    arr[0] = 0;
    arr[1] = 1;
    while(i <= n){
        arr[i] = arr[i-1]+arr[i-2];
        i++;
    }
    return arr[n];
    }
};