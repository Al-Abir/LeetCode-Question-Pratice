package Array;

public class Container_Water {
    public static int maxArea(int[] height) {
        int lp = 0;
        int rp = height.length - 1;
        int maxWater = Integer.MIN_VALUE;

        while (lp < rp) {
            int ht = Math.min(height[lp], height[rp]);
            int width = rp - lp;
            int current_area = width * ht;
            maxWater = Math.max(maxWater, current_area);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }

        return maxWater;
    }

    public static void main(String[] args) {
  
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = maxArea(height);
        System.out.println("Maximum water that can be stored: " + result);
    }
}
