package Array;

public class Pow {
    public static double myPow(double x, int n) {
        long N = n; // Convert to long to handle Integer.MIN_VALUE

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while (N != 0) {
            if (N % 2 == 1) {
                result *= x;
                N--;
            } else {
                x *= x;
                N /= 2;
            }
        }

        return result;
    }

    // Main method to test the power function
    public static void main(String[] args) {
        double x = 2.00000;
        int n = 10;

        double result = myPow(x, n);
        System.out.println("Result: " + result);
    }
}
