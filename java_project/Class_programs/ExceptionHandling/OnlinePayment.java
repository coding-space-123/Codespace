import java.util.Scanner;

public class OnlinePayment {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            // Product validation
            System.out.print("Enter product price: ");
            double price = sc.nextDouble();

            if (price <= 0) {
                throw new IllegalArgumentException("Invalid product price.");
            }

            System.out.println("Product validation successful.");

            // Inner try for payment
            try {

                System.out.print("Enter payment amount: ");
                double payment = sc.nextDouble();

                if (payment < price) {
                    throw new ArithmeticException("Insufficient payment.");
                }

                System.out.println("Payment successful.");

            } catch (ArithmeticException e) {

                System.out.println("Payment Failed: " + e.getMessage());
            }

            System.out.println("Final Order Status: Processing completed.");

        } catch (Exception e) {

            System.out.println("Order Failed: " + e.getMessage());
        }

        sc.close();
    }
}