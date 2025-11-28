// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).
 

// Constraints:

// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        // Way 1: Using Erase()
        // Time complexity: O(n^2) worst case
        int removeElementway1(std::vector<int>& nums, int val){
            int k = nums.size();
            // Collect all indexes where nums[i] equals val
            std::vector<int> post_list;
            for(int i = 0; i < nums.size(); i++){
                // If the current element equals val, decrease k and record its index
                if(val == nums[i]){
                    k--;
                    post_list.push_back(i);
                }
            }
            // Sort the index list in descending order
            sort(post_list.begin(), post_list.end(), std::greater<int>());

            // Erase elements at the collected indexes from right to left
            for(auto &pos : post_list){
                nums.erase(nums.begin() + pos);
            }
            return k;
        }

        // Way 2: In-place 2 pointers
        // Time complexity: O(n)
        int removeElementway2(std::vector<int>& nums, int val){
            int k = 0;
            for(int i = 0; i < nums.size(); i++){
                // Just need to check case nums[i] != val to move value of current index to left
                if(nums[i] != val){
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }

};

int main()
{
    std::vector<int> nums = {2,5,2,1,5};
    int val = 2;
    Solution s;
    std::cout << s.removeElementway1(nums, val) << std::endl;
    return 0;
}