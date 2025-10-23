// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

#include <iostream>
using namespace std;
class Solution{
    public:
        int reverse(int x){
            // Check for the constraint -2^31 <= x <= 2^31 - 1
            if(x >= -(1LL << 31) && x <= ((1LL << 31) - 1)) {
                long reverve_num = 0;
                if(x > 0) {
                    while(x % 10 != 0 || (x % 10 == 0 && x > 0)) {
                        reverve_num = reverve_num * 10 + x % 10;
                        x /= 10;
                        // Check for overflow before it happens
                        if(reverve_num < -(1LL << 31) || reverve_num > ((1LL << 31) - 1))
                            return 0;
                    }
                }
                else if(x == 0){
                    return 0;
                }
                else{
                    while(x % 10 != 0 || (x % 10 == 0 && x < 0)){
                        reverve_num = reverve_num * 10 + x % 10;
                        x /=10;
                        if(reverve_num > 0)
                            reverve_num = -reverve_num;
                        // Check for overflow before it happens
                        if(reverve_num < -(1LL << 31) || reverve_num > ((1LL << 31) - 1)) 
                            return 0;
                    }
                }
                return reverve_num;
               
            }
            else {
                return 0;
            }
        }
};
int main() {
    Solution solution;
    int x = 123;
    cout << solution.reverse(x);
    return 0;
}