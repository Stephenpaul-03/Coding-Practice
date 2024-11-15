import java.util.*;

public class Floor {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            sc.nextLine();
            for (int i = 0; i < t; i++) {
                int[] arr = Arrays.stream(sc.nextLine().split(" "))
                                  .mapToInt(Integer::parseInt)
                                  .toArray();
                int x = sc.nextInt();
                sc.nextLine();

                int n = arr.length;
                int low = 0; 
                int high = n - 1;
                int idx = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (arr[mid] == x) {
                        idx = mid;
                        break;
                    } else if (arr[mid] < x) {
                        idx = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                if (idx == -1) {
                    System.out.println("-1");
                } else {
                    System.out.println(arr[idx]);
                }
            }

            sc.close();
        }
    }
}
