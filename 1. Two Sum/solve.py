# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# Example 1:

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
# Example 2:

# Input: nums = [3,2,4], target = 6
# Output: [1,2]

class Solution(object):
    def twoSum(self, nums, target):
        # The idea is to declare a dictionary as a hashmap to store key pairs after each comparison loop
        num_map = {}
        for i, num in enumerate(nums):
            # Do subtraction while simultaneously comparing with the value in the hashmap so that the algorithm's complexity is O(n) instead of O(n²) like the traditional nested for loops.
            if target - num  in num_map:
                return [num_map[target - num],i]
            num_map[num] = i

solution = Solution()
nums = [2, 7, 9, 1]
target = 10
print(solution.twoSum(nums, target))