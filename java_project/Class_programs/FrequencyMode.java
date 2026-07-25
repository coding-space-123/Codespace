import java.util.Scanner;

public class FrequencyMode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        boolean visited[] = new boolean[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int mode = arr[0];
        int maxFreq = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    visited[j] = true;
                }
            }
            System.out.println(arr[i] + " -> Frequency = " + count);
            if (count == 1)
                System.out.println(arr[i] + " is Unique");

            if (count > 1)
                System.out.println(arr[i] + " is Duplicate");

            if (count > maxFreq) {
                maxFreq = count;
                mode = arr[i];
            }
        }
        System.out.println("Mode = " + mode);
        sc.close();
    }
}