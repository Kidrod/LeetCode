// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.


// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


// Constraints:

// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution{
public:
    // Method to convert roman numeral to digit
    int romanToInt(const std::string &s){

        // Initialize an unordered_map to store Roman numerals and their integer values
        static const std::unordered_map<char, int> Roman_num = {{'M',1000}, {'D',500}, {'C',100}, {'L',50}, {'X',10}, {'V',5}, {'I',1}};

        // Variable to store the final result once fully converted
        int final_result = 0;

        // Loop to go through the size of s string input
        for(int i = 0; i < s.length(); i++)
        {
            // Subtractive rule for special cases like IV, IX, XL, XC,...
            if(i + 1 < s.length() && Roman_num.at(s[i]) < Roman_num.at(s[i+1])){
                final_result -= Roman_num.at(s[i]);
            }
            // Otherwise, apply Additive rule
            else{
                final_result += Roman_num.at(s[i]);
            }

        }
        return final_result;   
    }

    // Method to check the input is valid or not
    bool isValidRoman(const std::string &s){

        // Declare a set of valid characters of roman numeral
        static const std::unordered_set<char> validChars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        // Check lenght of s string first, compare to the constraint
        if(s.length() < 1 || s.length() > 15){
            return false;
        }
        else{
            // Loop to go through the array
            for(char c : s){
                // Condition to find character of s string appearing in valid array, return false value if can't find
                if(validChars.find(c) == validChars.end())
                    return false;
            }
        }
        // Otherwise, return true value
        return true;
    }
};

int main(){
    Solution solution;
    std::string s = "DCCCLXXII";
    if(solution.isValidRoman(s))
        std::cout << solution.romanToInt(s);

    else
        std::cout << "Invalid Roman numeral";
    return 0;
}