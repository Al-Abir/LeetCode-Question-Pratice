package Array;

public class Remove_sorted {
    public static int Remove_sorted_duplicate(int nums[]){
        int j =1;
        for(int i =1; i<nums.length; i++){
            if(nums[i]!=nums[i-1]){
                nums[j]= nums[i];
                j++;
            }
        }
        return j++;
    }
    public static void main(String[] args) {
        int arr[]= {0,0,1,1,1,2,2,3,3,4};
        int result =  Remove_sorted_duplicate(arr);
        for(int i =0; i<result; i++){
            System.out.println(arr[i]);
        }
    }
}
