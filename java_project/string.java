import java.util.Scanner;

public class string {
    public static void main(String[] args) {
        int a = 6;
    
        float b = 3.4f;
        Scanner sc = new Scanner (System.in);
        String st = sc.nextLine();
        System.out.println(st);
        String name = new String("Vaishnavi");
        System.out.print("The name is : ");
        System.out.println(name);
        System.out.printf("the value of a is %d and value of b is %.2f ", a, b);
        System.out.format("the value of a is %d and value of b is %.2f ", a, b);

    }
}