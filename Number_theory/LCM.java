package Number_theory;
import java.util.Scanner;

public class LCM {
    public static int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        int ans = (a*b)/gcd(a,b);

        System.out.println(ans);
    }
}
