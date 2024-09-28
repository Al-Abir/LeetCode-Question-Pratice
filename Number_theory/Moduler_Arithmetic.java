package Number_theory;

public class Moduler_Arithmetic {
    public static int modpower(long x, long n, long m){
         long result = 1;
         long base = x %m;
         while(n>0){
             if(n%2==1){
                result = (result*base)%m;
             }
             base = (base*base)%m;
             n = n/2;
         }
         return (int)result;

    }
    public static void main(String[] args) {
        
        System.out.println(modpower(5,2,7));
    }
}
