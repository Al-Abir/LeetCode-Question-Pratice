package Array;

public class Maximum_Subarray {
    public static int maxSubArray(int[] nums) {
        int currSum = 0;
        int maximum = nums[0];

        for (int i = 0; i < nums.length; i++) {
            currSum += nums[i];
            maximum = Math.max(maximum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maximum;
    }

    public static void main(String[] args) {
       
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int result = maxSubArray(nums);
        System.out.println("Maximum subarray sum is: " + result);
    }
}
