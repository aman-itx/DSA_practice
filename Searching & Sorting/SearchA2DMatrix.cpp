// Problem: Search a 2D Matrix
// Platform: LeetCode (74)
// Topic: Binary Search
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();            // no. of rows
        int n = matrix[0].size();         // no.of cols
        int l = 0, h= (m*n) - 1,mid;
        while(l <= h)
        {
            mid = l+ ((h-l)/2);
            int row = mid / n;              // denotes row number
            int col = mid % n;              // denotes col number
            int value = matrix[row][col];
            if(value == target)
            return true;
            else if(value < target)         // move right
            {
                l = mid + 1;
            }
            else                            // move left---> value > target
            {
                h = mid - 1;
            }
        }
        return false;  
    }
};
