package Combinatorics;

public class Binomial_Coefficient {
    static int binomial(int n , int k){
        if(k>n) return 0;
        if(k==0 || k==n){
            return 1;
        }else{
             return binomial(n-1, k-1)+ binomial(n-1, k);
        }
    }
    public static void main(String[] args) {
        int n =5;
        int k =2;
        System.out.println(binomial(n,k));
    }
}
