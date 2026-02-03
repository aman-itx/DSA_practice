// Problem: Count of Smaller Numbers After Self
// Platform: LeetCode (315)
// Topic: Searching & Sorting
// Technique: Merge Sort / BIT / Segment Tree
// Difficulty: Hard

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> count(n, 0);                 // answer array
        vector<pair<int,int>> arr;               // {value, original index}

        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, 0, n - 1, count);
        return count;
    }

    void mergeSort(vector<pair<int,int>>& arr, int l, int r, vector<int>& count)
    {
        if (l >= r) return; // single element
        int m = l + ((r - l) / 2);
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }

    void merge(vector<pair<int,int>>& arr, int l, int m, int r, vector<int>& count)
    {
        vector<pair<int,int>> t;

        int i = l;        // left half pointer
        int j = m + 1;    // right half pointer

        while (i <= m && j <= r)
        {
            if (arr[i].first <= arr[j].first) //// all right elements already moved are smaller
            {
                count[arr[i].second] += (j - (m + 1));
                t.push_back(arr[i]);
                i++;
            }
            else
            {
                t.push_back(arr[j]);
                j++;
            }
        }
        while (i <= m)          // remaining left elements
        {
            count[arr[i].second] += (j - (m + 1));
            t.push_back(arr[i]);
            i++;
        }
        while (j <= r)       // remaining right elements
        {
            t.push_back(arr[j]);
            j++;
        }
        for (int k = l; k <= r; k++)  //copy merged result back into original array
        {
            arr[k] = t[k - l];
        }
    }
};
