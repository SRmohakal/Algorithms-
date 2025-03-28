import java.util.Scanner;

public class NaiveStringMatching {
    public static void naiveApproach(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();
        boolean found = false;

        for (int i = 0; i <= n - m; i++) { // Sliding over text
            boolean match = true;
            for (int j = 0; j < m; j++) { // Checking each character
                if (text.charAt(i + j) != pattern.charAt(j)) {
                    match = false;
                    break; // If mismatch found, break
                }
            }
            if (match) {
                System.out.println("Pattern found at index " + i + ".");
                found = true;
            }
        }

        if (!found) {
            System.out.println("Pattern not found.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the text: ");
        String text = scanner.next();
        System.out.print("Enter the pattern: ");
        String pattern = scanner.next();
        
        naiveApproach(text, pattern);
        
        scanner.close();
    }
}
