package Array;

public class Delete_Operation {
    static int findElement(int arr[], int n, int k){
        int i;
        for(i=0; i<n; i++){
            if(arr[i]==k){
                return i;
            }
        }
        return -1;
    }

    static int Deletion_element(int arr[], int n, int k){
          int pos = findElement(arr, n, k);
          if(pos == -1){
            System.out.println("Not Found");
            return n;
          }else{
               for(int i =pos; i<n-1; i++){
                 arr[i]= arr[i+1];
               }
          }
          return n-1;
    }
    public static void main(String[] args) {
        int i;
        int arr[] = { 10, 50, 30, 40, 20 };

        int n = arr.length;
        int key = 30;

        System.out.println("Array before deletion");
        for (i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        
    
    System.out.println("\n");
     n = Deletion_element(arr, n, key);
     for(i =0; i<n; i++){
        System.out.println(arr[i]);
     }
    
    }
}