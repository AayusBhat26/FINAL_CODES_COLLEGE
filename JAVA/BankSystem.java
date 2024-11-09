// 7. Program to maintain bank account. Extend Bank account details to current and saving account (Java).
import java.util.Scanner;
class BankAccount {
    protected String accountNumber;
    protected String accountHolderName;
    protected double balance;
    public BankAccount(String accountNumber, String accountHolderName, double initialBalance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
    }
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
        } else {
            System.out.println("Insufficient balance or invalid withdrawal amount.");
        }
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder: " + accountHolderName);
        System.out.println("Balance: " + balance);
    }
}

// Extended class for Savings Account
class SavingAccount extends BankAccount {
    private final double interestRate;

    public SavingAccount(String accountNumber, String accountHolderName, double initialBalance, double interestRate) {
        super(accountNumber, accountHolderName, initialBalance);
        this.interestRate = interestRate;
    }

    public void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        System.out.println("Interest added: " + interest);
    }

    @Override
    public void displayAccountDetails() {
        super.displayAccountDetails();
        System.out.println("Account Type: Savings");
        System.out.println("Interest Rate: " + interestRate + "%");
    }
}

// Extended class for Current Account
class CurrentAccount extends BankAccount {
    private final double overdraftLimit;

    public CurrentAccount(String accountNumber, String accountHolderName, double initialBalance, double overdraftLimit) {
        super(accountNumber, accountHolderName, initialBalance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance + overdraftLimit) {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
            if (balance < 0) {
                System.out.println("Warning: Account is in overdraft.");
            }
        } else {
            System.out.println("Insufficient funds including overdraft limit.");
        }
    }

    @Override
    public void displayAccountDetails() {
        super.displayAccountDetails();
        System.out.println("Account Type: Current");
        System.out.println("Overdraft Limit: " + overdraftLimit);
    }
}

public class BankSystem {
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
