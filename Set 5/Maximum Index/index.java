import java.util.*;
class index {
    public static int Index_Difference(int arr[], int n) {
        int max_difference = 0;

        int[] left_Minimum = new int[n];
        int[] right_max = new int[n];

        left_Minimum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left_Minimum[i] = Math.min(arr[i], left_Minimum[i - 1]);
        }

        right_max[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            right_max[j] = Math.max(arr[j], right_max[j + 1]);
        }

        int i = 0, j = 0;
        while (i < n && j < n) {
            if (left_Minimum[i] <= right_max[j]) {
                max_difference = Math.max(max_difference, j - i);
                j++;
            } else {
                i++;
            }
        }
        return max_difference;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            sc.nextLine();
            
            for (int i = 0; i < t; i++) {
                int[] arr = Arrays.stream(sc.nextLine().split(" "))
                                   .mapToInt(Integer::parseInt)
                                   .toArray();
                int n = arr.length;
                System.out.println(Index_Difference(arr, n));
                
            }
        }
    }
}


