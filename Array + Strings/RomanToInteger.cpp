// Problem: Roman to Integer
// Platform: LeetCode (13)
// Topic: Strings
// Difficulty: Easy

class Solution {
public:
// Time Complexity: O(n)
// Space Complexity: O(1)
    int romanToInt(string s)
    {
        unordered_map<char,int>value={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i,result=0,n=s.length();
        for(i=0; i<n; i++)
        {
            if(i+1 < n && value[s[i]] < value[s[i+1]] )  //Subtract current value
            {
                result-=value[s[i]];
            }
            else                                        // Add
            {
                result+=value[s[i]];
            }
        }
        return result;
    }
};
