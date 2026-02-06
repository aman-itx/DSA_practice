// Problem: Pow(x, n)
// Platform: LeetCode (50)
// Topic: Binary Search, Math
// Technique: Fast Exponentiation
// Difficulty: Medium

class Solution {
public:
// Time Complexity: O(log n)
// Space Complexity: O(1), (Recursive version → Space O(log n))
    double myPow(double x, int n)
    {
        long long exp = n;
        double result = 1.0;
        if(exp < 0)
        {
            exp = - exp;
            x = 1/x;
        }
        while(exp > 0)
        {
            if(exp % 2 == 1) // n = odd
            {
                result *= x;
            }
            x *= x; // squaring the number
            exp /= 2;
        }
        return result;           
    }
};
