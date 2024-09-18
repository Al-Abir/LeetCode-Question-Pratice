package leetCode_15_Pattern;
import java.util.Scanner;
public class two_pointer {
    static int[] prefixSum(int[] arr) {
        int m = arr.length;
        // int[] newArray = new int[m];
        // newArray[0] = arr[0];
    
        for (int i = 1; i < arr.length; i++) {
            // newArray[i] = newArray[i - 1] + arr[i];
            arr[i]=arr[i-1]+arr[i];
        }
        return arr;
        // return newArray;
    }
    
    static void PrintArray(int[]arr){
        for(int i =0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.err.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i =0; i<n; i++){
            arr[i]= sc.nextInt();
        }

        PrintArray(arr);

        int[]prefix = prefixSum(arr);
        PrintArray(prefix);
    }
}
