// Problem: Find Peak Element
// Platform: LeetCode (162)
// Topic: Binary Search
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int findPeakElement(vector<int>& nums)
    {
        int l=0, h=nums.size()-1,m;
        while(l < h)
        {
            m = l + ((h-l)/2);
            if(nums[m] > nums[m+1])  // peak on left side
            {
                h = m;
            }
            else // peak on right side
            {
                l = m + 1;
            }
        }
        return l;
    }
};
