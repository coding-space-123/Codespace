class InsufficientBalanceException extends Exception {

    public InsufficientBalanceException(String message) {
        super(message);
    }
}

class BankAccount {

    double balance;

    BankAccount(double balance) {
        this.balance = balance;
    }

    void transfer(BankAccount receiver, double amount)
            throws InsufficientBalanceException {

        if (amount > balance) {

            throw new InsufficientBalanceException(
                    "Insufficient Balance.");
        }

        if (amount <= 0) {

            throw new IllegalArgumentException(
                    "Invalid transfer amount.");
        }

        balance -= amount;
        receiver.balance += amount;

        System.out.println("Transaction Successful.");
    }
}

public class BankTransfer {

    public static void main(String[] args) {

        BankAccount sender = new BankAccount(5000);
        BankAccount receiver = new BankAccount(2000);

        try {

            sender.transfer(receiver, 7000);

        } catch (InsufficientBalanceException e) {

            System.out.println(
                    "Transaction Failed: Insufficient Balance.");

        } catch (IllegalArgumentException e) {

            System.out.println(e.getMessage());
        }

        System.out.println("Sender Balance = " + sender.balance);
        System.out.println("Receiver Balance = " + receiver.balance);
    }
}