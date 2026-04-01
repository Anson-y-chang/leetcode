#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      // 初步建立 window
      if (count < target) {
        count += nums[i];
        int temp = 0;
        // 加完 right 後大於 target
        while (count > target) {
          // 判定 left 需不需要右移
          if (nums[i] < nums[left]) {
            continue;
          }

          if (count - nums[left] > target || nums[i] > nums[left]) {
            left++;
          }
        }
      }
    }
  }
};

// Input: target = 7, nums = [2,3,1,2,4,3,1,7]
// Output: 2
int main() {
  Solution s;
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};

  cout << s.minSubArrayLen(target, nums) << endl;
}