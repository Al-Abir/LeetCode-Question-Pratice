package Number_theory;

import java.util.Scanner;

public class Seive {
     
    public static void seive(int n) {
        
        boolean[] prime = new boolean[n + 1];
       
        for (int i = 2; i * i <= n; i++) {
            if (!prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = true; 
                }
            }
        }


        for (int i = 2; i <= n; i++) {
            if (!prime[i]) { // If still false, it's a prime number
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int a = sc.nextInt();

        // Call the seive function
        seive(a);
    }
}
