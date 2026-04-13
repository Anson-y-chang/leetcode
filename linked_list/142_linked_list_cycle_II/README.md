// description
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

// solution
1. record_and_find
  1.1 using vector to store pointers, find pos and return index
  1.2 using hash table to store pointers, O(),  find pos and return index

2. two pointers
  https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md

  

// time complexity
1. record_and_find
  1.1 vector, O(nm)
    linked_list len = n
    recorded vector len = m, which could be 0~n
  1.2 hash table, O(n)
    visited.count(curr->next) cost O(1), n times cost O(n)

2. two pointers, O(n)
  
