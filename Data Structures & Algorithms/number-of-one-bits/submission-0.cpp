// Bit manipulation 
// for bit 0 ~ 31
//   make a mask  n & (1 << 4)
//   compare with the n -> check if the nth bit is 1 
//   sum the number of 1s     

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;

        for(int i=0;i<32;i++){
            result += (n & (1 << i)) >> i; // O(n)
        }

        return result;
    }
};
