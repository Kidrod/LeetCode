// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.



// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]


// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words){
        std::vector<std::string> result;
        // Loop through each character in the first word
        for(char c : words[0]){
            bool found_in_all = true;
            // Check if this character c exists in all other words
            for(int i = 1; i < words.size(); i++){
                size_t pos = words[i].find(c);
                if(pos != std::string::npos)
                    // Remove character c once to avoid counting duplicates
                    words[i].erase(pos, 1);
                else{
                    // If the character c is missing in any word, mark as false and break the loop
                    found_in_all = false;
                    break;
                }
            }
            if(found_in_all)
                // Add character was found to the result variable
                result.push_back(std::string(1,c));
        }
        return result;
    }
};

int main()
{
    std::vector<std::string> words = {"coffee", "juice", "lemonade"};
    Solution sol;
    std::cout << sol.commonChars(words)[0]; // Expected result: {"e"}
    return 0;
}