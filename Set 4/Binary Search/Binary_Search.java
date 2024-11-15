import java.util.*;

public class Binary_Search {

    public static int search(int[] arr, int x) {
        int n = arr.length;
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                return mid; 
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; 
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int t = scanner.nextInt();
            scanner.nextLine(); 

            for (int i = 0; i < t; i++) {
                
                int[] arr = Arrays.stream(scanner.nextLine().split(" "))
                                  .mapToInt(Integer::parseInt)
                                  .toArray();
                
                int x = scanner.nextInt();
                scanner.nextLine(); 

                System.out.println(search(arr, x));
            }
        }
    }
}
