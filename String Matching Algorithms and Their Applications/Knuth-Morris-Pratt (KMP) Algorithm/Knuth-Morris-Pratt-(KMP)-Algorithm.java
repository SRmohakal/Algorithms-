import java.util.Scanner;

public class KMPAlgorithm {

    public static int[] computeLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int length = 0;
        int i = 1;

        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(length)) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    public static void KMP(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();
        int[] lps = computeLPS(pattern);

        int i = 0, j = 0;
        boolean found = false;

        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                System.out.println("Pattern found at index " + (i - j));
                j = lps[j - 1];
                found = true;
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        if (!found) {
            System.out.println("Pattern not found in the text.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the text: ");
        String text = scanner.next();
        System.out.print("Enter the pattern: ");
        String pattern = scanner.next();

        int[] lps = computeLPS(pattern);
        System.out.print("LPS Array: ");
        for (int num : lps) {
            System.out.print(num + " ");
        }
        System.out.println();

        KMP(text, pattern);
        scanner.close();
    }
}
