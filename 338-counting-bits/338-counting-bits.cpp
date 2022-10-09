class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1);
        //k비트라고 했을 때, 상위 k-1 bit는 answer[i/2]와 같다.
        //자리수가 2의 거듭제곱일 때 늘어나는 것이 특징이다.
        
        //=> 1 : 0001
        
        //=> 2 : 0010
        //=> 3 : 0011
        
        //=> 4 : 0100   => 2의 2배 + 0, 2의 2배 +1
        //=> 5 : 0101   
        //=> 6 : 0110  => 3의 2배 +0, 3의 2배 + 1
        //=> 7 : 0111

        //=> 8 : 1000 ...
        //그래서 DP 문제다.
        for (int i = 1; i <= n; ++i){
            answer[i] = answer[i/2] + (i & 1);
        }
        return answer;
    }
};