package Array;

import java.util.Scanner;

public class Inset_End {
    static int insertEnd(int arr[], int n, int k, int capacity){

        if(n>=capacity){
            return n;
        }
        arr[n]= k;

        return n+1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[20];
        int n =5;
        System.out.println("Before insert : ");
        for(int i =0; i<n; i++){
            arr[i]= sc.nextInt();
        }   
        int key =26;
        int capacity= 20;
         n = insertEnd(arr, n, key, capacity);

        System.out.println("After insert : ");
        for(int i =0; i<n; i++){
           System.out.print(" " + arr[i]);
        }
    }
}
