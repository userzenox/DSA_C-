#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = col - 1;

        while(rowIndex < row && colIndex>=0 ){
              int element = matrix[rowIndex][colIndex];
                         
              if(element == target){
                return 1;
              }
              if(element < target){
                 rowIndex++;
              }
              else{
                colIndex--;
              }
        }
     return 0;
       
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in matrix." << endl;
    } else {
        cout << "Target not found in matrix." << endl;
    }

    return 0;
}
