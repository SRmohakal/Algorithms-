import java.util.Scanner;

public class RabinKarpAlgorithm {
    static final int d = 256;
    static final int q = 101;

    public static void rabinKarp(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m > n) {
            System.out.println("Pattern is longer than the text.");
            return;
        }

        int h = 1;
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        int p_hash = 0, t_hash = 0;
        for (int i = 0; i < m; i++) {
            p_hash = (d * p_hash + pattern.charAt(i)) % q;
            t_hash = (d * t_hash + text.charAt(i)) % q;
        }

        boolean matchFound = false;
        for (int i = 0; i <= n - m; i++) {
            if (p_hash == t_hash && text.substring(i, i + m).equals(pattern)) {
                System.out.println("Pattern found at index " + i);
                matchFound = true;
            }

            if (i < n - m) {
                t_hash = (d * (t_hash - text.charAt(i) * h) + text.charAt(i + m)) % q;
                if (t_hash < 0)
                    t_hash += q;
            }
        }

        if (!matchFound)
            System.out.println("Pattern not found in the text.");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the text: ");
        String text = scanner.next();

        System.out.print("Enter the pattern: ");
        String pattern = scanner.next();

        rabinKarp(text, pattern);
        scanner.close();
    }
}
