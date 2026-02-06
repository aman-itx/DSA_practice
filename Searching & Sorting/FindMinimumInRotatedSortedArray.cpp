// Problem: Find Minimum in Rotated Sorted Array
// Platform: LeetCode (153)
// Topic: Binary Search
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int findMin(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1, mid;
        while(low < high)
        {
            mid = low + ((high - low)/2);
            if(nums[mid] > nums[high] )            // left side sorted----> minimum element at right side
            {
                low = mid + 1;
            }
            else
            {
                high = mid;                      //right side sorted----> minimum element at left side
            }
        }
        return nums[low];                       // high == low
    }
};
