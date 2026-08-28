class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        
        # print(hashmap)
        for i in range(len(nums)):
            pair = target - nums[i]
            if pair in hashmap:
                if i != hashmap[pair]:
                    return [i, hashmap[pair]]
        
        return []





        