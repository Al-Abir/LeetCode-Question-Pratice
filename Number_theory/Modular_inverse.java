package Number_theory;

import java.util.Scanner;

public class Modular_inverse {
      public static int inverse(long base , long power, long module){
          long res =1;
          base = base%module;
        while(power>0){
            if(power%2==1){
               res = (res*base)%module;
            }
            base = (base*base)%module;
            power = power/2;

        }
        return (int)res;

      }
      public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int m = sc.nextInt();
        int calculate = inverse(2,m-2,m);
        int ans  = (a*calculate)%m;
        System.out.println(ans);

      }
}
