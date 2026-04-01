#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[count] = nums[i];
        count++;
      }
    }

    return count;
  }
};

// Input: nums = [0,1,2,3,2,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_,_]
int main() {
  Solution s;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;

  cout << s.removeElement(nums, val) << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}