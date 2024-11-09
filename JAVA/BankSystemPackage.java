//8. Program to maintain Bank Account using packages (Java).
import java.util.Scanner;
import bank_package.bank.SavingAccount;
import bank_package.bank.CurrentAccount;
public class BankSystemPackage {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create accounts for testing
        SavingAccount savingAccount = new SavingAccount("S123456", "Aayush Kumar Bhat", 1000.0, 3.5);
        CurrentAccount currentAccount = new CurrentAccount("C123456", "Aayush Kumar Bhat", 2000.0, 500.0);

        boolean exit = false;
        while (!exit) {
            System.out.println("\n=== Bank System ===");
            System.out.println("1. Display Savings Account Details");
            System.out.println("2. Display Current Account Details");
            System.out.println("3. Deposit to Savings Account");
            System.out.println("4. Withdraw from Savings Account");
            System.out.println("5. Deposit to Current Account");
            System.out.println("6. Withdraw from Current Account");
            System.out.println("7. Add Interest to Savings Account");
            System.out.println("8. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    savingAccount.displayAccountDetails();
                    break;
                case 2:
                    currentAccount.displayAccountDetails();
                    break;
                case 3:
                    System.out.print("Enter deposit amount for Savings Account: ");
                    double savingDeposit = scanner.nextDouble();
                    savingAccount.deposit(savingDeposit);
                    break;
                case 4:
                    System.out.print("Enter withdrawal amount for Savings Account: ");
                    double savingWithdraw = scanner.nextDouble();
                    savingAccount.withdraw(savingWithdraw);
                    break;
                case 5:
                    System.out.print("Enter deposit amount for Current Account: ");
                    double currentDeposit = scanner.nextDouble();
                    currentAccount.deposit(currentDeposit);
                    break;
                case 6:
                    System.out.print("Enter withdrawal amount for Current Account: ");
                    double currentWithdraw = scanner.nextDouble();
                    currentAccount.withdraw(currentWithdraw);
                    break;
                case 7:
                    savingAccount.addInterest();
                    break;
                case 8:
                    exit = true;
                    System.out.println("Exiting the system.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
        scanner.close();
    }
}
