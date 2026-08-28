class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> existed; 

        for(int i=0; i<nums.size(); i++){
            int wanted = target - nums[i];
            printf("%d \n", wanted);
            if(existed.find(wanted) == existed.end()){
                existed[nums[i]] = i;
            }
            else{
                return {existed[wanted], i};
            }
        }

        return {};
    }
};
