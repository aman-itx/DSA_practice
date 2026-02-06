// Problem: Kth Smallest Number in Multiplication Table
// Platform: LeetCode (668)
// Topic: Binary Search
// Difficulty: Hard

class Solution {
public:
// Time Complexity: O(m * log(mn))
// Space Complexity: O(1)
    int findKthNumber(int m, int n, int k)
    {
        int l=1, h= m*n,i;
        while(l < h)
        {
            int mid = l + ((h-l)/2);
            long long count = 0;
            for(i=1; i <= m; i++)
            {
                count+=min(n,mid/i);
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
