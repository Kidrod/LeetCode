// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:

// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:

// Input: p = [1,2], q = [1,null,2]
// Output: false

// Example 3:

// Input: p = [1,2,1], q = [1,1,2]
// Output: false

#include <iostream>
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; // both are null
        if(!p || !q) return false; // 1 null, 1 not null
        if(p->val != q->val) return false; // not equal val

        // Recursion
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    TreeNode* p = new TreeNode(1);
    TreeNode* p_left = new TreeNode(2);
    TreeNode* p_right = new TreeNode(1);
    p->left = p_left;
    p->right = p_right;
    
    TreeNode* q = new TreeNode(1);
    TreeNode* q_left = new TreeNode(1);
    TreeNode* q_right = new TreeNode(2);
    q->left = q_left;
    q->right = q_right;
    
    Solution solution;
    std::cout << solution.isSameTree(p,q);
    return 0;
}