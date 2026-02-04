// Problem: Multiply Two Strings
// Platform: GeeksforGeeks
// Topic: Math, Strings
// Difficulty: Medium

class Solution {
  public:
    string multiplyStrings(string s1, string s2)
    {
        int n=s1.size(), m=s2.size(),i,j,k,k1,k2,shift,carry,sum,prod;
        vector<int> ans(n+m, 0);
        string a;
        vector<int> product(n+m, 0);
        
        for(j=m-1; j>=0; j--)
        {
            if(s2[j] == '-')
            {
                break;
            }
            
            shift= m-1-j;
            carry=0;
            
            for(i=0; i<n+m; i++)
            {
                product[i]=0;
            }
            
            k1= s2[j] -'0';
            
            for(i=n-1,k=n+m-1-shift; i>=0; i--,k--)
            {
                if(s1[i] == '-')
                {
                    break;
                }
                k2=s1[i]-'0';
                prod= k1*k2 + carry;
                if(prod>=10)
                {
                    product[k]= prod % 10;
                    prod/=10;
                    carry= prod;
                }
                else
                {
                    product[k]= prod;
                    carry= 0;
                }
            }
            
            if(carry>0)
            {
                product[k]= carry;
            }
            carry=0;
            
            for(i=n+m-1; i>=0; i--)
            {
                sum= product[i] + ans[i] + carry;
                
                if(sum>=10)
                {
                    ans[i]= sum % 10;
                    sum/=10;
                    carry= sum;
                }
                else
                {
                    ans[i]= sum;
                    carry= 0;
                }
            }
        }
        
        i=0;
        
        while(i < n + m && ans[i] == 0)
        {
            i++;
        }
        
        if(i == n + m)
        {
            return "0";
        }
        
        if(s1[0] == '-' && s2[0] != '-')
        {
            a+= '-';
        }
        else if(s1[0] != '-' && s2[0] == '-')
        {
            a+= '-';
        }
        
        for(; i<n+m; i++)
        {
            a+= char(ans[i] + 48);
        }
        
        return a;
    }
};
