// to reverse the string: 
// abcd -> dcba 
// abcd -> dbca -> dcba -> break from the loop 
// abc -> cba 
// using two pointers (use index)
//  -> head + tail 
// traverse through the string(array) 
//  swap head, tail pointing two chars
//  Only use one additional char  
// Time: O(N), Space: O(1)

// head: first char -> mid
// tail: end char -> mid 

class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = 0;
        int tail = s.size()-1;

        while(tail > head){
            // swap the values
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
            
            // move pointers
            head++;
            tail--;
        }
    }
};