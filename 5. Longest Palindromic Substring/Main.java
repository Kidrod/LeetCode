class Solution{
    public String longestPalindrome(String s){
        String res = s.charAt(0) + "";
        if(s == null || s.length() == 0)
            return "";
        else {
            for(int i = 0; i < s.length() - 1; i++){
                for(int j = i + 1; j < s.length(); j++){
                    // Compare two chars at position i and j
                    if(s.charAt(i) == s.charAt(j)){ 
                        // Extract substring from index i to j
                        String sub = s.substring(i, j + 1);
                        // Reverse substring
                        String reversed = new StringBuilder(sub).reverse().toString();
                        // Check if substring is a palindrome and longer than the current result
                        if(sub.equals(reversed) && sub.length() > res.length()){
                            res = sub;
                        }
                    }
                }
            }
        }
        return res;
    }
}


public class Main{
    public static void main(String[] args){
        Solution sol = new Solution();
        String s = sol.longestPalindrome("ab");
        System.out.println(s);
    }
}
