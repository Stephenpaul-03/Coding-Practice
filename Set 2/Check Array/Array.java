import java.util.*;

public class Array {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            sc.nextLine();
            
            for (int i = 0; i < t; i++) {
                int[] arr1 = Arrays.stream(sc.nextLine().split(" "))
                                   .mapToInt(Integer::parseInt)
                                   .toArray();
                int[] arr2 = Arrays.stream(sc.nextLine().split(" "))
                                   .mapToInt(Integer::parseInt)
                                   .toArray();
                
                if (arr1.length != arr2.length) {
                    System.out.println("No");
                    continue;
                }
                
                Map<Integer, Integer> count = new HashMap<>();
                for (int num : arr1) {
                    count.put(num, count.getOrDefault(num, 0) + 1);
                }

                boolean flag = true;
                for (int num : arr2) {
                    if (!count.containsKey(num) || count.get(num) == 0) {
                        System.out.println("No");
                        flag = false;
                        break;
                    } else {
                        count.put(num, count.get(num) - 1);
                    }
                }

                if (flag) {
                    System.out.println("Yes");
                }
            }

            sc.close();
        }
    }
}
