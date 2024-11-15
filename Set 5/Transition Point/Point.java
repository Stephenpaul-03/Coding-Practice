import java.util.*;

public class Point {
    
    public static int transition(int[] arr) {
        int low = 0;
        int high = arr.length - 1;
        int idx = -1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (arr[mid] == 1) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return idx;
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            sc.nextLine();
            
            for (int i = 0; i < t; i++) {
                int[] arr = Arrays.stream(sc.nextLine().split(" "))
                                   .mapToInt(Integer::parseInt)
                                   .toArray();
                System.out.println(transition(arr));
                
            }
        }
    }
    
}