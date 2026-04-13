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
    ListNode *curr = head;
    unordered_map<ListNode *, int> visited;
    int index = 0;

    while (curr) {
      // 存入當前
      visited[curr] = index++;

      // 找到
      if (visited.count(curr->next)) {
        cout << "tail connects to node index " << visited[curr->next] << endl;
        return curr->next;
      }

      curr = curr->next;
    }

    cout << "no cycle" << endl;
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