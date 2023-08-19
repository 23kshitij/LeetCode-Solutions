class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int i = 0;

        while (i < k) {
            if (nums[i] == val) {
                nums[i] = nums[k - 1]; // Replace current element with the last one
                k--; // Decrease the size of the "valid" part of the array
            } else {
                i++; // Move to the next element
            }
        }

        return k;
    }
};
