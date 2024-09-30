package Number_theory;

public class Chinese {  
    static int findMinx(int num[], int rem[], int k){
        int x =1;

        while(true){
            int j;
           for(j =0 ; j<k; j++){
            if( x% num[j] != rem[j]){
                break;
            }
           
           }
           if(j==k){
            return x;
        }
           x++;
        }
    }
    public static void main(String[] args) {
        
        int num[]= {3,4,5};
        int rem[]=  {2,3,1};
        int k = num.length;
        System.out.println("x is " + findMinx(num, rem, k));

    }
}
