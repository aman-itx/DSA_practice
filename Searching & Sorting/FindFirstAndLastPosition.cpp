// Problem: Find First and Last Position of Element in Sorted Array
// Platform: LeetCode (34)
// Topic: Searching & Sorting
// Difficulty: Medium

class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size()-1, ans = -1,mid;

        while(low <= high) {
            mid = low +((high-low)/2);

            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, ans = -1,mid;

        while(low <= high) {
            mid = low +((high-low)/2);

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> result(2, -1);

        if (nums.empty()) return result;

        result[0] = findFirst(nums, target);
        if (result[0] == -1) return result;

        result[1] = findLast(nums, target);
        return result;
    }
};
