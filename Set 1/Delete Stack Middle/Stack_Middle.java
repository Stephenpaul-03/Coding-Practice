import java.util.*;

public class Stack_Middle {
    public static void deleteMiddle(Stack<Integer> stack, int n) {
        deleteMiddleHelper(stack, n, 0);
    }

    private static void deleteMiddleHelper(Stack<Integer> stack, int size, int currentIndex) {
        if (stack.isEmpty() || currentIndex == size / 2) {
            stack.pop();
            return;
        }

        int top = stack.pop();
        deleteMiddleHelper(stack, size, currentIndex + 1);
        stack.push(top);
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            Stack<Integer> stack = new Stack<>();

            System.out.println("Enter the elements of the stack (space-separated):");
            String[] elements = scanner.nextLine().split(" ");
            for (String element : elements) {
                stack.push(Integer.valueOf(element));
            }
            deleteMiddle(stack, stack.size());
            System.out.println("Stack after deleting middle element: " + stack);
        }
    }
}
