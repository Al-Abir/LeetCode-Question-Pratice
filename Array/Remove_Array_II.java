package Array;

public class Remove_Array_II {
    // Make Solution class static
    public static class Solution {
        public int removeDuplicates(int[] nums) {
            if (nums.length <= 2) {
                return nums.length;
            }
            int k = 2;
            for (int i = 2; i < nums.length; i++) {
                if (nums[i] != nums[k - 2]) {
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }
    }

    public static void main(String[] args) {
        int nums[] = {1, 1, 1, 2, 2, 3};

        // Instantiate the static Solution class directly
        Solution sol = new Solution();
        int result = sol.removeDuplicates(nums);
        System.out.println(result);
    }
}
