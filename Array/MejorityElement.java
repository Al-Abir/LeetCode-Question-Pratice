package Array;

import java.util.HashMap;
import java.util.Map;
public class MejorityElement {
     public static int majorityElement(int nums[]){
        int len = nums.length;
        Map<Integer,Integer> freq = new HashMap<>();

        for(int n : nums){
            freq.put(n, freq.getOrDefault(n,0)+1);
        }

        for(Map.Entry<Integer, Integer> m : freq.entrySet()){
            if(m.getValue()> len/2){
                return m.getKey();
            }
        }

        /*for (Integer key : freq.keySet()) {
            if (freq.get(key) > len / 2) {
                return key;
            }
        }
        */
        
        return -1;
     }
      public static void main(String[] args) {
        
        int nums[] = {3,2,3};

      System.out.println(majorityElement(nums)); 
      }
}
