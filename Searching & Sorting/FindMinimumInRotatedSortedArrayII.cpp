// Problem: Find Minimum in Rotated Sorted Array II
// Platform: LeetCode (154)
// Topic: Binary Search
// Difficulty: Hard

class Solution {
public:
// Time Complexity: O(log n) average, O(n) worst-case
// Space Complexity: O(1)
    int findMin(vector<int>& nums)
    {
        int l= 0, h=nums.size()-1,m;
        while(l < h)
        {
            m = l + ((h-l)/2);
            if(nums[m] > nums[h] )                       //left side sorted, minimum at right side
            {
                l = m + 1;
            }
            else if(nums[m] < nums[h] )                // right side sorted, minimum at left side
            {
                h = m;
            }
            else                                     // nums[m] == nums[h], shrink the search space of high by 1, removes 1 duplicates
            {
                h--;
            }
        }
        return nums[l];
    }
};
