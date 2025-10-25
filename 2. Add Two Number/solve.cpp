#include <iostream>

// Define ListNode type
struct ListNode {
    // A node contains 2 parameters, one is value of itself, one is the pointer to next node
    int val;
    ListNode *next;
    // List node empty
    ListNode() : val(0), next(nullptr) {}
    // List node has 1 node only
    ListNode(int x) : val(x), next(nullptr) {}
    // List node has multiple nodes
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            int carry = 0; // carry stores the overflow when the sum of two digits exceeds 9
            ListNode dummy = ListNode(0); // dummy node acts as a placeholder head for the result list
            ListNode* curr = &dummy; // pointer to build the result of linked list
            // Loop to add values node by node
            while(l1 != nullptr || l2 != nullptr || carry > 0){

                int x = (l1 != nullptr) ? l1->val : 0; // get value of a node of first linked list
                int y = (l2 != nullptr) ? l2->val : 0; // get value of a node of second linked list

                int sum = x + y + carry; // compute sum of them
                carry = sum / 10; // then compute current carry

                // append the digit node to the result list
                curr->next = new ListNode(sum % 10); 
                curr = curr->next;

                // Move to next node of l1 and l2
                if(l1) 
                    l1 = l1->next;
                if(l2)  
                    l2 = l2->next;

            }
            // Return the linked list result
            return dummy.next;

        }
};

// Helper function to create a linked list from an array
ListNode* createList(const int a[], int size){
    ListNode dummy(0);
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
    return;
}

int main(){
    int num1[] = {1,2,3};
    int num2[] = {0,9,5};

    ListNode* l1 = createList(num1, 3);
    ListNode* l2 = createList(num2, 3);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1,l2);
    printList(result);
    return 0;
}