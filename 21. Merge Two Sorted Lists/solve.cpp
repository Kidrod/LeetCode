// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <iostream>


// Define ListNode structure type
struct ListNode{
    // A ListNode or linked nodes contains some standalone nodes in there
    int val;
    ListNode* next;

    // Define constructors
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

            // Decleare nessessary vars, dummy acts as placeholder of head, curr to store final calculation node by node
            ListNode dummy = ListNode(0);
            ListNode* curr = &dummy;
            // Compare list1 to list2 node by node
            while(list1 && list2){
                if(list1->val < list2->val){
                    curr->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else{
                    curr->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                curr = curr->next;
            }

            // Append the rest of list1 if it has nodes left
            while (list1)
            {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
                curr = curr->next;
            }

            // Append the rest of list2 if it has nodes left
            while (list2)
            {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;  
                curr = curr->next;
            }
            return dummy.next;
        }
};

// Helper function to create a linked list from an array
ListNode* createList(const int a[], int size){
    ListNode dummy = ListNode(0);
    ListNode* curr = &dummy;
    for(int i = 0; i < size; i++){
        curr->next = new ListNode(a[i]);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* l){
    while(l){
        std::cout << l->val;
        if(l->next)
            std::cout << " -> ";
        l = l->next;
    }
    std::cout << std::endl;
}

// Helper function to validate input
bool isSortedList(const int a[], int count){
    if(count > 50)
        return false;
    for(int i = 0; i < count; i++){
        if(a[i] > 100 || a[i] < -100)
            return false;
    }
    for(int i = 0; i < count - 1; i++){
        if(a[i] > a[i+1])
            return false;
    }
    return true;
}

int main(){
    // Declare 2 ascending sorted list 
    int num1[] = {1,5,8};
    int num2[] = {3,4,6};

    if(isSortedList(num1, 3) && isSortedList(num2,3)){
        ListNode* l1 = createList(num1, 3);
        ListNode* l2 = createList(num2, 3);


        Solution solution;
        ListNode* result = solution.mergeTwoLists(l1,l2);

        printList(result);
    }
    else    
        std::cout << "Invalid input";
    return 0;
}