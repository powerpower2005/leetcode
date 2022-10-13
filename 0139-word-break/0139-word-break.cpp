class Solution {
public:
    //dp[i] : dp[i]부터 끝까지 단어로 쪼갤 수 있느냐? 1 : -1
    //dp[0] : 문자열 전부를 끝까지 단어로 쪼갤 수 있느냐?
    
    
    int x;
    int check(string &s, int idx, vector<string> &dict, vector<int> &dp){
        
        if(idx == x){
            return 1;
        }
        
        int &result = dp[idx];

        if(result != -1){
            return result;
        }
        //cout << result << '\n';
        result = 0; // result를 0으로 초기화하는 이유.  -1이 아니어야 바로 반환하기 때문
        for(auto w : dict){
            int wSize = w.size();
            if(idx + wSize > x)continue;
            string comp = s.substr(idx, wSize);
            if(comp == w){
                result = check(s, idx + wSize, dict, dp);  //하나라도 1이면 가능
                if(result == 1)return result;
            }
        }
        
        return result;
        
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        x = s.size();
        vector<int> dp(x+1,-1);
        
        return check(s, 0, wordDict, dp) == 1;
    }
};