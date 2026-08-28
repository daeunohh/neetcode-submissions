class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        appeared = set([])
        for n in nums:
            if n in appeared:
                return True
            appeared.add(n)
        return False
        