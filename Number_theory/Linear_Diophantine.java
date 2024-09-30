package Number_theory;

public class Linear_Diophantine {
    static int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
    static boolean isPossible(int a, int b, int c){
         return (c% gcd(a,b)==0);
    }
    public static void main(String[] args) {
        
        int a =3, b=6, c=9;
        if(isPossible(a, b, c)){
            System.out.println("Possible");
        }else{
            System.out.println("Not Possiable");
        }
           // Second example
           a = 3; b = 6; c = 8;
           if(isPossible(a, b, c))
               System.out.println( "Possible") ;
           else
               System.out.println( "Not Possible");
    }
}
