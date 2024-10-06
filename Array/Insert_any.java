package Array;

import java.util.Scanner;

public class Insert_any {
    static void insertElement(int arr[] , int n, int pos, int value){
        for(int i = n-1; i>=pos; i--){
            arr[i+1]= arr[i]; 
        }
        arr[pos]= value;
    }
    public static void main(String[] args) {
        int arr[] = new int[20];
        int n =5;

        Scanner sc = new Scanner(System.in);
        for(int i =0; i<n; i++){
            arr[i]= sc.nextInt();
        }

        int pos=2;
        int value =40;

        insertElement(arr, n, pos, value);
        n = n+1;

        for(int i =0; i<n; i++){
            System.out.println(arr[i]);
        }
    }
}
