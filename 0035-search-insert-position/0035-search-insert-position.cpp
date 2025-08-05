class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int result = n;
        while(l<=h) {
            int mid = l+ (h-l)/2;
            if(nums[mid]==target) {
                return mid;
            }
            else if(nums[mid]>target) {
                result = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return result;
    }
};