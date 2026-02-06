// Problem: Maximum Nesting Depth of the Parentheses
// Platform: LeetCode (1614)
// Topic: Strings
// Difficulty: Easy

class Solution {
public:
// Time Complexity: O(n)
// Space Complexity: O(1)

    int maxDepth(string s)
    {
        int current = 0, maxvalue = 0,i;
        for(i=0; i < s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(' )
            {
                current++;
                maxvalue = max(current,maxvalue);
            }
            else if(ch == ')' )
            {
                current--;
            }
        }
        return maxvalue;
    }
};
