// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1

 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution{
    public:
        // Way 1: Sorted vector-based solution
        // Time complexity: O(n logn)
        int singleNumberway1(std::vector<int>& nums){
            // Sorting the input vector as ascending
            sort(nums.begin(),nums.end());
            // Compare adjacent pairs
            for(int i = 0; i < nums.size() - 1; i += 2){
                if(nums[i] != nums[i+1])
                    return nums[i];
            }
            // If single number located at the end of sorted vector. [1,1,3,3,6]
            return nums.back();
        }

        // Way 2: XOR-based solution
        // Time complexity: O(n)
        // XOR operator logic: 
        // 1 ^ 1 = 0
        // 1 ^ 0 = 1
        // 0 ^ 1 = 1
        // 0 ^ 0 = 0
        // ==> 1 ^ 1 ^ 2 = 2
        int singleNumberway2(std::vector<int>& nums){
            int result = nums[0];
            for(int i = 1; i < nums.size(); i++)
                result ^= nums[i]; // Compute XOR all elements of vector input
            return result;
        }

        // Way 3: Hash map-based solution
        // Time compexity: O(n)
        int singleNumberway3(std::vector<int>& nums){
            std::unordered_map<int, int> map_frequency;
            // Count the frequency of appearance then store to hash map
            for(int n : nums){
                map_frequency[n]++; // Example: nums ={1,3,5,3,1} ==> map_frequency = {1:2, 3:2, 5:1}
            }
            for(auto& res : map_frequency){
                if(res.second == 1) // Look for the <key:value> with value = 1 mean it is the single number
                    return res.first;
            }
            return -1;
        }

};

int main(){
    std::vector<int> nums = {1,2,2,1,6,4,4};
    Solution s;
    std::cout << s.singleNumberway1(nums) << std::endl;
    std::cout << s.singleNumberway2(nums) << std::endl;
    std::cout << s.singleNumberway3(nums);
    return 0;

}