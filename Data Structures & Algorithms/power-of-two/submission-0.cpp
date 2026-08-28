// return true if n is a power of two 

// brute force: keep dividing into 2 
//      -> if the remainer=1 -> false, else true 
//      Time: O(logN), Space:O(1)
//              keep multiplying 2 to 1
//      -> check if the result is bigger than or equal to n

// Dynamic programming: 
//      if called frequently, brute force + set data sturcture
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int poweroftwo = 1;
        // while(poweroftwo < n){ poweroftwo *= 2; }
        // return (poweroftwo == n);

        return (n > 0) && (n & (n - 1)) == 0;

        
        
    }
};