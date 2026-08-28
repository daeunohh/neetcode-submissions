// [Constraints]
// len s > len t 
//  if s == t: true

// [Outline]
// if t.size < s.size: return false 
// two pointers:
//  p1: first char in s
//  p2: first char in t 
// loop
    // p1 traverses through s 
    //  if p1 == p2: 
    //      if p2 == end of t: return true 
    //      p2++
    //  p1++
// return false 
// Time: O(N), Space: O(1) (N:len of s, M:len of t) 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()){
            return false;
        }
        if(s.size() == 0) return true;
        int i1 = 0, i2 = 0;
        while(i2 < t.size()){
            if(s[i1] == t[i2]){
                if(i1 == s.size() - 1){
                    return true;
                }
                i1++;
            }
            i2++;
        }
        return false;
    }
};