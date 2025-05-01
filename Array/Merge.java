package Array;
public class Merge {
   static public void merge(int[] nums1, int m, int[] nums2, int n) {
    
        int index1 = m - 1; // Pointer for the last element of the initial part of nums1
        int index2 = n - 1; // Pointer for the last element of nums2
        int merge = m + n - 1; // Pointer for the last position in nums1
       
        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] < nums2[index2]) {
                nums1[merge--] = nums2[index2--]; // Place nums2 element in nums1
            } else {
                nums1[merge--] = nums1[index1--]; // Place nums1 element in nums1
            }
        }
        
      
        while (index2 >= 0) {
            nums1[merge--] = nums2[index2--];
        }
    }
    
    public static void main(String[] args) {
        // Example input arrays
        int[] nums1 = {1, 2, 3, 0, 0, 0}; // nums1 with extra space for nums2
        int m = 3; // Number of initialized elements in nums1
        
        int[] nums2 = {2, 5, 6}; // Second sorted array
        int n = 3; // Number of elements in nums2


        merge(nums1, m, nums2, n);
        
        System.out.print("Merged array: ");
        for (int num : nums1) {
            System.out.print(num + " ");
        }
    }
}
