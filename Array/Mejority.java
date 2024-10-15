package Array;

public class Mejority {
    public static int majorityElement(int[] nums) {
        int n = nums.length;
        int majorityElement = nums[0]; // Initialize with the first element
        int maxCount = 0; // Track the maximum count of occurrences

        // Step 1: Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            int count = 0; // Count occurrences of nums[i]

            // Step 2: Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

         
            if (count > maxCount) {
                maxCount = count; // Update the max count
                majorityElement = nums[i]; // Update the majority element
            }
        }

        // The majority element should be the one with maxCount after the loops
        return majorityElement; 
    }

    public static void main(String[] args) {
        int[] nums1 = {3, 2, 3};
        System.out.println(majorityElement(nums1)); // Output: 3

        int[] nums2 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println(majorityElement(nums2)); 
    }
}
