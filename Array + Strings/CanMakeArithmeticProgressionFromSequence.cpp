// Problem: Can Make Arithmetic Progression From Sequence
// Platform: LeetCode (1502)
// Topic: Arrays
// Difficulty: Easy

class Solution {
public:
// Time Complexity: O(n log n), (O(1) if sorting in-place, otherwise O(n))
// Space Complexity: O(1)
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        int i,d=arr[1] - arr[0];
        bool ans = true;
        for(i=2; i < arr.size(); i++)
        {
            if(arr[i] - arr[i-1] != d)
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
