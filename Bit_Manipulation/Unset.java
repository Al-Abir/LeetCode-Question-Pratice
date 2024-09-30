package Bit_Manipulation;

public class Unset {
    public static void main(String[] args) {
        int a = 10;
        int pos =2;
        int Bit_mask = ~(1<<pos);

        int result = Bit_mask & a;
        System.out.println(result);
    }
}
