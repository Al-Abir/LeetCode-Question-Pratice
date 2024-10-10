package Array;

public class Remove {
    public int removeElement(int nums[], int val) {
        int index = 0; // To track the position for non-val elements

        int i = 0;
        while (i < nums.length) {
            // Check if the current element is not equal to val
            if (nums[i] != val) {
                nums[index] = nums[i]; // Move the element to the 'index' position
                index++; // Increment index for the next non-val element
            }
            i++;
        }
        return index; // Return the new length
    }

    public static void main(String[] args) {
        int nums[] = {3, 2, 2, 3}; // Input array
        int val = 3; // Value to be removed

        Remove solution = new Remove();
        int newLength = solution.removeElement(nums, val); // Store the new length

        // Print only the relevant part of the array
        System.out.print("[");
        for (int i = 0; i < newLength; i++) {
            System.out.print(nums[i]); // Print the valid elements
            if (i < newLength - 1) { // Add a comma if it's not the last element
                System.out.print(", ");
            }
        }
        System.out.println("]"); // Close the bracket
    }
}
