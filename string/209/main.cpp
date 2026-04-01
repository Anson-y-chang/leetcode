#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT_MAX;
    int left = 0;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      count++;
      while (sum - nums[left] >= target) {
        sum -= nums[left];
        left++;
        count--;
      }
      if (sum >= target) {
        res = min(res, count);
      }
    }

    if (sum < target) {
      return 0;
    }
    return res;
  }
};

int main() {
  Solution s;
  int target = 11;
  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  // vector<int> nums = {1, 4, 4};

  cout << s.minSubArrayLen(target, nums) << endl;
}