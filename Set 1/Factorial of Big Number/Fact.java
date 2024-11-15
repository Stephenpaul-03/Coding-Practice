import java.math.BigInteger;
import java.util.Scanner;

public class Fact {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a number to find its factorial: ");
            int num = scanner.nextInt();
            
            BigInteger result = BigInteger.ONE;
            for (int i = 1; i <= num; i++) {
                result = result.multiply(BigInteger.valueOf(i));
            }
            System.out.println(result);
        }
    }
}
