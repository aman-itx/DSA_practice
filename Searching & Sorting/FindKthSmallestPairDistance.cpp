// Problem: Find K-th Smallest Pair Distance
// Platform: LeetCode (719)
// Topic: Binary Search
// Difficulty: Hard

class Solution {
public:
// Time Complexity: O(n log n)
// Space Complexity: O(1)
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size(), l = 0, h = nums[n-1] - nums[0], mid;
        while(l < h)
        {
            mid = l + ((h-l)/2);
            int count=0,i,j=0;
            for(i=0; i<nums.size(); i++)
            {
                while(j<nums.size() && nums[j]-nums[i] <= mid)
                {
                    j++;
                }
                count+=j-i-1;                                    // valid pairs for index i
            }
            if(count < k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return l;           
    }
};
