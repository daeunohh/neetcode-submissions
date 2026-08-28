// 

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0){
            return 0;
        }
        int cnt = 0;

        for(int i=s.size()-1; i>=0; i--){       // O(N) -> O(logN) / O(1)
            if(s[i] == ' '){
                if(cnt > 0){
                    return cnt; 
                }
                continue;
            }
            cnt += 1;
        }
        
        return cnt;
    }
};
