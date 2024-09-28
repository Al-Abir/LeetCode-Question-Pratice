package Number_theory;

public class binary_expon {

    public static long power(long A, long B) {
        long res = 1;
        while (B > 0) {
            if (B % 2 == 1) {
                res = res * A;
                B--;
            } else {
                A = A * A;
                B = B / 2;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(power(2, 12));  // Expected output: 4096
    }
}
