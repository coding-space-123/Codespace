import java.util.Scanner;

public class FactorialTrailingZeros {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        long fact = 1;

        for (int i = 1; i <= n; i++)
            fact *= i;

        System.out.println("Factorial = " + fact);

        int zeros = 0;
        int temp = n;

        while (temp > 0) {
            temp /= 5;
            zeros += temp;
        }

        System.out.println("Trailing Zeros = " + zeros);

        sc.close();
    }
}