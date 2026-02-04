// Problem: Nth Magical Number
// Platform: LeetCode (878)
// Topic: Searching & Sorting
// Technique: Binary Search on Answer + LCM
// Difficulty: Hard

class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long lcm(long long x, long long y)
    {
        return((x/gcd(x,y))*y);
    }
    int nthMagicalNumber(int n, int a, int b)
    {
        long long l = min(a,b);
        long long h = (long long)n * min(a,b);
        long long common = lcm(a,b);
        while(l < h)
        {
            long long m = l + ((h-l)/2);
            long long count = m/a + m/b - m/common;
            if(count < n)
                l = m + 1;
            else
                h = m;
        }
        return l % MOD;
    }
};
