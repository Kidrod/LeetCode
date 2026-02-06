// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown.
// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30

#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> generate(int numRows){

            // Initialize a variable for output vector
            std::vector<std::vector<int>> result;

            for(int i = 0; i < numRows; i++){
                // A vector to store values of a row, put default value as 1 for all nodes inside
                std::vector<int> row(i + 1, 1);
                for(int j = 1; j < i; j++){
                    // Compute current node based on the two nodes above comming from the previous row
                    row[j] = result[i-1][j-1] + result[i-1][j];
                }
                
                // Each row is an element of output vector - the Pascal's triangle
                result.push_back(row);
            }

            return result;
        }
};

int main(){
    Solution sol;
    std::vector<std::vector<int>> triangle = sol.generate(5);
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}