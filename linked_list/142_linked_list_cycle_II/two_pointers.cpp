
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
      if (slow == fast) {
        ListNode *index1 = fast;
        ListNode *index2 = head;
        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
        }
        return index2; // 返回环的入口
      }
    }
    return nullptr;
  }
};

int main() {
  Solution s;
  // head = [3,2,0,-4], pos = 1
  vector<int> nodes = {3, 2, 0, 4};
  int pos = 1;
  ListNode *head = new ListNode(nodes[0]);
  ListNode *curr = head;
  ListNode *starter = nullptr;

  for (int i = 1; i < nodes.size(); i++) {
    curr->next = new ListNode(nodes[i]);
    curr = curr->next;

    if (i == pos) {
      starter = curr;
    }
  }
  curr->next = starter;

  curr = head;
  s.detectCycle(curr);
}