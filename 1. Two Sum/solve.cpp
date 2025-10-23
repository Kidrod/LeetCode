#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Declare a class to package all thing 
class Solution {
public:
    // Expected output is a vector {a, b}
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use unordered_map type to store <key,value> because not care about index order, need the hash table in this situation
        unordered_map<int,int> num_map;
        // Loop to go through the size of vector input
        for(int i = 0; i < nums.size(); i++){
            // Perform an operation target - num[i] and compare to some values be stored in the hash map
            if(num_map.find(target - nums[i]) != num_map.end()){
                // If find out, return the function with the index of both values having the sum equal to target
                return {num_map[target - nums[i]], i};
            }
            num_map[nums[i]] = i;
        }
        // Return an empty vector if cant find any proper result
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 5, 6, 8};
    int target = 11;
    cout << "Test case:";
    vector<int> result = solution.twoSum(nums, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]";
    return 0;
}