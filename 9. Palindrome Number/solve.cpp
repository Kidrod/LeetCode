// Given an integer x, return true if x is a palindrome, and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1
 

// Follow up: Could you solve it without converting the integer to a string?
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            // Check whether x is negative or x has the last num is 0
            if (x < 0 || (x % 10 == 0 && x != 0)) {
                return false;
            }
            // And a var to store reversed number
            int reverse_num = 0;
            // Loop until go over half length of x
            while (x > reverse_num) {
                reverse_num = reverse_num * 10 + (x % 10);
                x /= 10;
            }
            // If x has length even, compare x to reversed num. Else x has length odd, x now smaller than reversed num, so divide to check
            return (x == reverse_num || x == reverse_num / 10);
        }
};

int main() {
    Solution solution;
    int x = 0;
    cout << solution.isPalindrome(x);
    return 0;
}
