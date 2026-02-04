// Problem: Search in Rotated Sorted Array
// Platform: LeetCode (33)
// Topic: Searching & Sorting
// Technique: Modified Binary Search
// Difficulty: Medium

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l=0,r=nums.size()-1,m,ans=-1;
        while(l <= r)
        {
            m= l+((r-l)/2);
            if(nums[m] == target)                                         // target found
            {
                ans= m;
                return ans;
            }
            if(nums[l] <= nums[m])                                      // left half is sorted
            {
                if(nums[l] <= target && target < nums[m])              // search in left half
                {
                    r= m-1;
                }
                else
                {
                    l=m+1;                                          // search in right half
                }
            }
            else                                                   // right half is sorted
            {
                if(nums[m] < target && target <= nums[r])         // saearch in right half
                {
                    l=m+1; 
                }
                else
                {
                    r=m-1;                                    // search in left half
                }
            }

        }
        return ans;
    }
};
