// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        // Way 1: Brute-force (not efficient ==> Time limit exceeded)
        // Time complexity: O(n^2)
        int maxAreaway1(std::vector<int>& height){
            // Example input height = {2,4,8,10,9}
            int ans = 0;
            for(int i = 0; i < height.size() - 1; i++)
                for(int j = i + 1; j < height.size(); j++)
                    if(ans < (j-i) * std::min(height[i],height[j])) 
                        ans = (j-i) * std::min(height[i],height[j]);
            return ans;
        }
        // Bcoz the way 1 can be accepted in Leet code due to Time limit exceeded, it prefers another approach
        // Way 2: Two Index Pointers 
        // Time complexity: O(n)
        int maxAreaway2(std::vector<int>& height){
            int left = 0;
            int right = height.size() - 1;
            int ans = 0;
            // The loop continues when left is still less than right
            while(left < right){
                // Compare current value of ans to update larger amount
                ans = std::max(ans, (right - left) * std::min(height[left], height[right]));
                // Move index of the lesser value column
                if(height[left] <= height[right])
                    ++left;
                else
                    --right;
            }
            return ans;
        }
};

int main(){
    std::vector<int> height = {2,4,8,10,9};
    Solution s;
    std::cout << s.maxAreaway1(height) << std::endl;
    std::cout << s.maxAreaway2(height);
}