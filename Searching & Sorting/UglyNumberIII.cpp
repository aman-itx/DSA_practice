// Problem: Ugly Number III
// Platform: LeetCode (1201)
// Topic: Searching & Sorting
// Technique: Binary Search on Answer + LCM/GCD
// Difficulty: Medium

class Solution 
{
    public:
        long long lcm(long long x, long long y) 
        {
            return ((x / gcd(x,y)) * y);
        }
        int nthUglyNumber(int n, int a, int b, int c)
        {
            long long low= 1, high=2e9,mid;
            long long ab= lcm(a,b);
            long long bc= lcm(b,c);
            long long ca= lcm(c,a);
            long long abc= lcm(ab,c);

            while(low < high)
            {
                mid = low + ((high - low)/2);
                long long count = mid/a + mid/b +mid/c - mid/ab - mid/bc - mid/ca + mid/abc;

                if(count<n)
                {
                    low= mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
            return low;
        }
};
