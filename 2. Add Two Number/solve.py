# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Example 1:

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.


# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]


# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]

# class ListNode (object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# class Solution (object):
#     def addTwoNumbers(self, l1, l2):
#         return 0

# solution = Solution()
# l1 = [1,2,4]
# l2 = [2,6,4]
# print(solution.addTwoNumbers(l1,l2))



class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self, head=None):
        self.head = head
    def append(self, new_node):
            current = self.head
            if current:
                while current.next:
                    current = current.next
                current.next = new_node
            else:
                self.head = new_node
    def print(self):
        current = self.head
        while current:
            print(current.value)
            current = current.next

e1 = Node(6)
e2 = Node(2)
l1 = LinkedList(e1)
print(l1.print())



