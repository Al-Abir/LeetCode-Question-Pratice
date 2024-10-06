package Array;
public class Search {
    static int findElement(int arr[], int n, int key)
    {
           for(int i =0; i<n; i++){
              if(arr[i]==key){
                return i;
              }
           }
           return -1;
    }
    public static void main(String[] args) {
        
        int arr[] = {10,20,30,40,50};
        int n  = arr.length;
        int key = 40;

        int pos = findElement(arr, n, key);
        if(pos == -1){
             System.out.println("Not found");
        }else{
            System.out.println("Found" + (pos+1));
        }
    }
}
