class Solution {
public:
    int tribonacci(int n) {
        vector<int> vec(38);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 1;
        for(int i = 3; i<=n; i++){
            vec[i] = vec[i-1]+vec[i-2]+vec[i-3];
        }
        
        return vec[n];
    }
};