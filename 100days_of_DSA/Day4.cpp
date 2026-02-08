// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Return the number of elements not equal to val (k).
// After removal, the first k elements of nums should contain the elements not equal to val.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
