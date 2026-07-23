import java.util.Scanner;

public class NumberCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int temp = num, reverse = 0, strongSum = 0, armSum = 0;

        while (temp > 0) {
            int digit = temp % 10;

            // Reverse
            reverse = reverse * 10 + digit;

            // Strong Number
            int fact = 1;
            for (int i = 1; i <= digit; i++) {
                fact *= i;
            }
            strongSum += fact;

            // Armstrong Number (3-digit)
            armSum += digit * digit * digit;

            temp /= 10;
        }

        System.out.println("Reverse = " + reverse);

        if (reverse == num)
            System.out.println("Palindrome Number");
        else
            System.out.println("Not a Palindrome Number");

        if (strongSum == num)
            System.out.println("Strong Number");
        else
            System.out.println("Not a Strong Number");

        if (armSum == num)
            System.out.println("Armstrong Number");
        else
            System.out.println("Not an Armstrong Number");

        sc.close();
    }
}