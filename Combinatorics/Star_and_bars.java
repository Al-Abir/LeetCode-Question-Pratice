package Combinatorics;

public class Star_and_bars{

   static int combination(int N, int R){
      int ans =1;
      for(int i =0; i<R; i++){
        ans = ans * (N-i);
        ans = ans/ (i+1);
      }
      return  ans;
   }
   public static void main(String[] args) {
         int  N=5;
         int  R = 2;

         System.out.println(combination(N, R));
   }
}
