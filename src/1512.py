class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        num = 0
        occurances = {}
        for n in nums:
            occurance = occurances.get(n, 0)
            num += occurance
            occurances[n] = occurance + 1
        return num
