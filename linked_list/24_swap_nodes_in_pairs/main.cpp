#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *first_ptr;
    ListNode *next_ptr;
    int is_first = 1;
    if (!head || !head->next) {
      return head;
    }
    ListNode *head_ptr = head->next;
    while (head) {
      if (is_first) {
        first_ptr = head;
        if (head->next) {
          if (head->next->next) {
            if (head->next->next->next) {
              next_ptr = head->next;
              head->next = head->next->next->next;
            } else {
              next_ptr = head->next;
              head->next = head->next->next;
            }
          } else {
            next_ptr = head->next;
            head->next = nullptr;
          }
        } else {
          next_ptr = nullptr;
        }
        is_first = 0;
      } else {
        if (head->next) {
          next_ptr = head->next;
        } else {
          next_ptr = nullptr;
        }
        head->next = first_ptr;
        is_first = 1;
      }

      head = next_ptr;
    }
    return head_ptr;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  ListNode *head = new ListNode(nums[0]);
  ListNode *head_ptr = head;
  ListNode *current = head;
  for (int i = 1; i < nums.size(); i++) {
    current->next = new ListNode(nums[i]);
    current = current->next;
  }

  head_ptr = s.swapPairs(head);

  while (head_ptr) {
    cout << head_ptr->val << " ";
    head_ptr = head_ptr->next;
  }
}