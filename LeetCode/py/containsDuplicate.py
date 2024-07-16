class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mapOfAppereance = {}

        for i in nums:
            if i in mapOfAppereance:
                mapOfAppereance[i] += 1
            else:
                mapOfAppereance[i] = 1

            if mapOfAppereance[i] > 1:
                return True

        return False