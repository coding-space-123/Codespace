import java.util.Scanner;

public class RotateArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter K: ");
        int k = sc.nextInt();

        k = k % n;

        System.out.println("Left Rotation:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[(i + k) % n] + " ");
        }

        System.out.println();

        System.out.println("Right Rotation:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[(i - k + n) % n] + " ");
        }

        sc.close();
    }
}