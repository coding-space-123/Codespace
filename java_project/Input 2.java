import java.util.Scanner;

public class Input {
    public static void main(String[] args) {
        // Scanner scanner = new Scanner(System.in); // take input from user

        Scanner scanner1 = new Scanner(System.in); // take input from user
        System.out.print("Enter your name: "); // prompt user for input
        String name = scanner1.nextLine(); // read user input : " vaishnavi is good girl" give proper ouput " vaishnavi
                                          // is good girl" --> after space
        System.out.println("Hello, " + name + "!");
        System.out.println("enter number1 :");
        int number1 = scanner1.nextInt(); // read integer input
        System.out.println("You entered: " + number1);
        System.out.println("enter number2 :");
        int number2 = scanner1.nextInt();
        System.out.println("You entered: " + number2);
        int sum = number1 + number2; // calculate sum
        System.out.println("Sum of " + number1 + " and " + number2 + " is: " + sum);

        /*
         * // check expression validity
         * boolean b1 = scanner.hasNextInt(); // check if next input is boolean
         * System.out.println(b1); // print the result
         * 
         */

        // string
        // String str = scanner.next(); // read string input. print the string input
        // after space not print full line
        String str1 = scanner1.nextLine(); // read string input full line
        System.out.println("You entered string: " + str1);
    }
}