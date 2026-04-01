#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // n*n matrix
    int dir = 0;                                   // 0123 right down left up
    int row = 0;
    int col = 0;
    int top_bound = n;
    int bottom_bound = 0;

    for (int i = 1; i <= pow(n, 2); i++) {
      matrix[row][col] = i;

      // 邊界控制
      if (dir == 0) {               // when turn right
        if (col + 1 == top_bound) { // turn down
          dir = 1;
          row++;
        } else {
          col++;
        }
      } else if (dir == 1) {        // when turn down
        if (row + 1 == top_bound) { // turn left
          dir = 2;
          col--;
        } else {
          row++;
        }
      } else if (dir == 2) {          // when turn left
        if (col - 1 < bottom_bound) { // turn up
          dir = 3;
          row--;
        } else {
          col--;
        }
      } else if (dir == 3) {              // when turn up
        if (row - 1 < bottom_bound + 1) { // turn right
          dir = 0;
          col++;
          // 修正 bound
          top_bound -= 1;
          bottom_bound += 1;
        } else {
          row--;
        }
      }
    }
    return matrix;
  }
};

int main() {
  Solution s;
  int n = 5;

  vector<vector<int>> arr = s.generateMatrix(n);
  for (int i = 0; i < n; i++) {
    cout << arr[i][0] << arr[i][1] << arr[i][2] << arr[i][3] << arr[i][4]
         << endl;
  }
}