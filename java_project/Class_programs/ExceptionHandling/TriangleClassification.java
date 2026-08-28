import java.util.*;

class InvalidTriangleException extends Exception {

    public InvalidTriangleException(String message) {
        super(message);
    }
}

public class TriangleClassification {

    static void checkTriangle(int a, int b, int c)
            throws InvalidTriangleException {

        // Check positive sides
        if (a <= 0 || b <= 0 || c <= 0) {
            throw new InvalidTriangleException(
                    "Sides must be positive.");
        }

        // Triangle condition
        if (a + b <= c ||
                a + c <= b ||
                b + c <= a) {

            throw new InvalidTriangleException(
                    "Given sides cannot form a valid triangle.");
        }

        // Classification
        if (a == b && b == c) {

            System.out.println("Triangle is Equilateral.");

        } else if (a == b || b == c || a == c) {

            System.out.println("Triangle is Isosceles.");

        } else {

            System.out.println("Triangle is Scalene.");
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            System.out.print("Enter side 1: ");
            int a = sc.nextInt();

            System.out.print("Enter side 2: ");
            int b = sc.nextInt();

            System.out.print("Enter side 3: ");
            int c = sc.nextInt();

            checkTriangle(a, b, c);

        } catch (InputMismatchException e) {
            System.out.println("enter side in int data type: " + e.getMessage());
        } catch (InvalidTriangleException e) {

            System.out.println("Error: " + e.getMessage());
        }

        sc.close();
    }
}