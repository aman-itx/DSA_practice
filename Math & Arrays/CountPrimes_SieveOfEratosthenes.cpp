// Problem: Count Primes
// Platform: LeetCode (204)
// Topic: Math, Number Theory
// Technique: Sieve of Eratosthenes
// Difficulty: Medium

class Solution
{
    public:
        int countPrimes(int n)
        {
            if(n<=2) return 0;
            static bool prime[5000001];
            int i,j,count=0;

            for(i=0; i<n; i++)
            {
                prime[i] = true;
            }

            for(i=2; i*i<n; i++)
            {
                if(prime[i])
                {
                    for(j=i*i; j<n; j+=i)
                    {
                        prime[j] = false;
                    }
                }
            }

            for(i=2; i<n; i++)
            {
                if(prime[i])
                {
                    count++;
                }
            }

            return count++;
        }
};
