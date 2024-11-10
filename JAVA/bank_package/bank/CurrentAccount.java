package bank_package.bank;

public class CurrentAccount extends BankAccount {
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
