// Problem: Search a 2D Matrix II
// Platform: LeetCode (240)
// Topic: Searching
// Technique: Staircase Search
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(m + n)
// Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size();    // returns no of rows
        int n=matrix[0].size(); //no of columns in 0th or 1st row
        int row=0, col=n-1;      // starting from top-right
        while(row < m && col >= 0)
        {
            if(matrix[row][col] == target )
            {
                return true;
            }
            else if(matrix[row][col] > target)
            {  // Move left
                col--;
            }
            else
            {    // Move down--> matrix[row][col] < target
                row++;
            }
        }
        return false;
    }
};
