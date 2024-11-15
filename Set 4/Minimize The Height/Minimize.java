import java.util.*;

class Minimize {
    static int Mini(int[] a, int n, int k) {
        Arrays.sort(a);
        int ans = a[n - 1] - a[0];
        int lar = a[n - 1] - k, sml = a[0] + k;
        
        for (int i = 0; i < n - 1; i++) {
            int min = Math.min(sml, a[i + 1] - k);
            int max = Math.max(lar, a[i] + k);
            if (min < 0) continue;
            ans = Math.min(ans, max - min);
        }
        return ans;
    }    
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter No. of Test Cases: ");
            int t = scanner.nextInt();
            scanner.nextLine();
            
            for (int test = 0; test < t; test++) {
                System.out.print("Enter value for n: ");
                int n = scanner.nextInt();
                System.out.print("Enter value for k: ");
                int k = scanner.nextInt();
                scanner.nextLine();
                
                int[] arr = Arrays.stream(scanner.nextLine().split(" "))
                                  .mapToInt(Integer::parseInt)
                                  .toArray();
                
                System.out.println(Mini(arr, n, k));
            }
            
            scanner.close();
        }
    }
}
