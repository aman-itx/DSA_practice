// Problem: Largest Prime Factor
// Platform: GeeksforGeeks
// Topic: Math, Number Theory
// Difficulty: Medium

class Solution {
  public:
    long long largestPrimeFactor(long long n) 
    {
        long long m= sqrt(n), ans=0,k,i,j;
        
        for(i=2; i<=m; i++)
        {
            if(n%i == 0)
            {
                ans= max(ans,i);
                while(n%i == 0)
                {
                    n/= i;
                }
            }
        }
        
        if(n> 1)
        {
            ans= n;
        }
        
        return ans;
    }
};
