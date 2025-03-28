import java.util.Arrays;
import java.util.Scanner;

public class GreedyCoinChange {
    public static void greedyCoinChange(int[] denominations, int amount) {
        Arrays.sort(denominations);
        reverseArray(denominations); // Sorting in descending order
        
        System.out.print("Coins used: ");
        for (int coin : denominations) {
            while (amount >= coin) {
                amount -= coin;
                System.out.print(coin + " ");
            }
        }
        System.out.println();
    }

    // Helper function to reverse an array (Descending Order)
    public static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of denominations: ");
        int n = scanner.nextInt();
        
        int[] denominations = new int[n];
        System.out.print("Enter the denominations: ");
        for (int i = 0; i < n; i++) {
            denominations[i] = scanner.nextInt();
        }

        System.out.print("Enter the amount: ");
        int amount = scanner.nextInt();

        greedyCoinChange(denominations, amount);
        
        scanner.close();
    }
}
