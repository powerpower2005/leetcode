#include<vector>

class Solution {
public:
    

    int fib(int n) {
        if (n < 2)return n;
        vector<int> answer(31);
        answer[0] = 0;
        answer[1] = 1;
        for(int i = 2; i<=n; i++){
            answer[i] = answer[i-1] + answer[i-2];
        }
        
        return answer[n];
        
        
    }
};