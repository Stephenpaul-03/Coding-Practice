import java.util.*;

class Checker {
    public static int Check(long arr[]) {
        int n = arr.length;
        if (n == 1) return 1;
        
        long[] prefix = new long[n];
        long[] suffix = new long[n];

        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) {
                return i + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int t = scanner.nextInt();
            scanner.nextLine(); 
            
            for (int test = 0; test < t; test++) {
                long[] arr = Arrays.stream(scanner.nextLine().split(" "))
                                   .mapToLong(Long::parseLong)
                                   .toArray();
                
                System.out.println(Check(arr));
            }
            
            scanner.close();
        }
    }
}
