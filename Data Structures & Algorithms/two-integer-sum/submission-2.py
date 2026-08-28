# Time: N, Space: N
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevmap = dict()
        
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in prevmap:
                return [prevmap[diff], i]
            else:
                prevmap[nums[i]] = i
        
        return []





        