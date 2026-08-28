import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        rev_count = dict()

        for num in nums:
            count[num] = count.get(num, 0) + 1
            rev_count
        print(count)

        pq = []
        for key, value in count.items():
            heapq.heappush(pq, (-value, key))
        print(pq)
        
        kv = []
        for t in range(k):
            kv.append(heapq.heappop(pq)[1])
        
        return kv


        