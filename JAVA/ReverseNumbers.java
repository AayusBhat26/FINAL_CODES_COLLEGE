import java.util.Scanner;

public class ReverseNumbers {
    public static int reverse(Integer number) {
        Integer temp = number;
        Integer res = 0;
        while (temp > 0) {
            res = res * 10 + temp % 10;
            temp = temp / 10;
        }
        return res;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of integers you want to reverse:");
        int n = scanner.nextInt();
        
        Integer[] numbers = new Integer[n]; // Array to store the numbers
        
        System.out.println("Enter the numbers:");
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        
        System.out.println("Reversed numbers:");
        for (int i = 0; i < n; i++) {
            Integer reversedNumber = reverse(numbers[i]);
            System.out.println("Original: " + numbers[i] + ", Reversed: " + reversedNumber);
        }
        
        scanner.close();
    }
}
