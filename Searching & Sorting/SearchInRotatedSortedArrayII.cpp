// Problem: Search in Rotated Sorted Array II
// Platform: LeetCode (81)
// Topic: Searching & Sorting
// Technique: Modified Binary Search (duplicates)
// Difficulty: Medium

class Solution {
    public:
        bool search(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1,m;
        while (l <= r)
        {
            m = l + ((r - l) / 2);
            if (nums[m] == target)                                                 // target found
            {
                return true;
            }
            if (nums[l] == nums[m])                                              // shrink the search space by 1 step
            {
                l++;
            }
            else if (nums[l] < nums[m])                                        // left half sorted
            {
                if (nums[l] <= target && target < nums[m])                    // search in left half
                {
                    r = m - 1;
                }
                else                                                        // search in right half
                {
                    l = m + 1;
                }
            }
            else                                                         // right half sorted
            {
                if (nums[m] < target && target <= nums[r])             // search in right half
                {
                    l = m + 1;
                }
                else                                                // search in left half
                {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};
