// Problem: Sum of Subarrays
// Platform: GeeksforGeeks
// Topic: Arrays
// Technique: Contribution Technique
// Difficulty: Medium

class Solution {
  public:
    int subarraySum(vector<int>& arr)
    {
        int i,n=arr.size();
        long long totalsum = 0;
        for(i=0; i < n; i++)
        {
            totalsum += (long long)arr[i]*(i+1)*(n-i);
        }
        return totalsum;
    }
};
