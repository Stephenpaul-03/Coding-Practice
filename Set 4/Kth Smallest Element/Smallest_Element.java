import java.util.*;

public class Smallest_Element {

    public static int element_finder(int[] arr, int n) {
        PriorityQueue<Integer> heap = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : arr) {
            heap.offer(num);
            if (heap.size() > n) {
                heap.poll();
            }
        }
        return heap.peek();
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int t = scanner.nextInt();
            scanner.nextLine();
            for (int i = 0; i < t; i++) {
                int[] arr = Arrays.stream(scanner.nextLine().split(" "))
                                  .mapToInt(Integer::parseInt)
                                  .toArray();
                int n = scanner.nextInt();
                scanner.nextLine();
                System.out.println(element_finder(arr, n));
            }
        }
    }
}
