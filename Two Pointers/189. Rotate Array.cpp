class Solution {
private:
    void reverseSegment(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        if (k == 0 || n <= 1) {
            return;
        }
        reverseSegment(nums, 0, n - 1);
        reverseSegment(nums, 0, k - 1);
        reverseSegment(nums, k, n - 1);
    }
};
