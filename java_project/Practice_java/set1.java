import java.util.Scanner;

public class set1 {
    public static void main(String[] args) {
        // question 1st : add three no.
        int a =3 ;
        int b =7 ;
        int c =4 ;
        int sum = a+b+c;
        System.out.println("Sum of a, b, and c is: " + sum);
        

        // question 2 : wap to calcuate cgpa of 3 subjects
        float sub1= 99;
        float sub2= 98;
        float sub3= 99;
        float cgpa = (sub1 + sub2 + sub3)/30;
        System.out.println("CGPA is: " + cgpa);

        // question 3 : which ask the user to enetr name ,and greets them
        // "hello <name>" , have a good day" text
        System.out.println("what is ur name :");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        System.out.println("Hello " + name + ", have a good day!");

        //question 4: covert kilometer to meter 
        System.out.println("enter distance in kilometer :");
        Scanner sc = new Scanner(System.in);
        int km = sc.nextInt();
        int meter = km * 1000;
        System.out.println("Distance in meter is: " + meter);


        // question 5: wap to find user enetr integer or not 
        System.out.println("enter uer number :");
        Scanner sc1 = new Scanner(System.in);
        System.out.println(sc1.hasNextInt());
        System.out.println("u have entered an integer: " + sc1.nextInt());
        }
}
