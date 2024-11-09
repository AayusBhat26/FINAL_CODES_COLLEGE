// 6. Program to print the reverse of the numbers; the numbers is taken as input from the user(Java).
import java.util.Scanner;
public class reverseNumber {
    public static int reverse(Integer number) {
        Integer temp = number;
        Integer res = 0;
        while (temp > 0) {
            res = res * 10 + temp % 10;
            temp = temp / 10;
        }
        return res;
    }
    public static void main(String args[]){
        Integer number ;
        Scanner SC = new Scanner(System.in);
        System.out.println("\nProvide an Integer value");
        number = SC.nextInt();
        Integer res = reverse(number);
        System.out.println("Before: " + number + ", after reversal :" + " " + res);
        SC.close();
    }
}
