// Problem: Single Element in a Sorted Array
// Platform: LeetCode (540)
// Topic: Binary Search
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int singleNonDuplicate(vector<int>& nums)
    {
        int l=0, h=nums.size()-1,m;
        while(l < h)
        {
            m = l+((h-l)/2);
            if(m % 2 == 1)                // mid is odd
            {
                m--;
            }
            if(nums[m] == nums[m+1])     // elements are same, index pairing have not changed
            {
                l= m+2;                 // single elem on right side
            }
            else
            {
                h = m;                   // elements on left side
            }
        }
        return nums[l];
    }
};
