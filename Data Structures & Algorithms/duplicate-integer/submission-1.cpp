// set data stucture 

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> existing = {};

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(existing.find(num) == existing.end()){
                existing.insert(nums[i]);
                continue;
            }
            else{
                return true;
            }
        }
        return false;
    }
};