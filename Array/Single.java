package Array;

public class Single {

    public static int singleNumber(int[] nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {4, 1, 2, 1, 2};

        int result = singleNumber(nums);

        System.out.println("The single number is: " + result);
    }
    
}
