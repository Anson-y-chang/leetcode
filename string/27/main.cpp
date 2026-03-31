#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (target == nums[i]) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 3, 5, 9, 12};

  cout << s.search(nums, 9) << endl;
}