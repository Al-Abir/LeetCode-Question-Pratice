package Array;

import java.util.HashSet;

public class Missing_Repeated {
    public static  int[] findMissingAndRepeatedValues(int[][] grid) {
        HashSet<Integer> set = new HashSet<>();
        int n = grid.length;
        int sq = n * n;
        int[] ans = new int[2];  // ans[0] = repeated, ans[1] = missing
        int Cursum = 0;

        for (int i = 0; i < n; i++) {
         
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (set.contains(val)) {
                    ans[0] = val; // repeated number
                } else {
                    set.add(val);
                    Cursum += val;
                }
            }
        }

        int totalSum = sq * (sq + 1) / 2;
        ans[1] = totalSum - Cursum; // missing number
        return ans;
    }
    public static void main(String[] args) {
        int[][] grid = {
            {1, 2},
            {2, 3}
        };

        int[] result = findMissingAndRepeatedValues(grid);

        System.out.println("Repeated: " + result[0] + ", Missing: " + result[1]);
    }
}
