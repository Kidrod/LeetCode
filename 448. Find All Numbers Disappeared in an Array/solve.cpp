// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
 

// Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums){
            for(int i = 0; i < nums.size(); i++){
                // Leverage the index to find out disappreared numbers, the numbers which meet requirement, are positive numbers
                int index = abs(nums[i]) - 1;
                nums[index] = abs(nums[index]);
                nums[index] = -nums[index];
            }
            std::vector<int> result;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > 0)
                    result.push_back(i + 1);
            }
            return result;
        }
};

int main(){
    std::vector<int> nums = {3,5,7,8,1,1,2,2};
    Solution sol;
    std::vector<int> result = sol.findDisappearedNumbers(nums);
    for(int x : result)
        std::cout << x << " ";
    return 0;
}
