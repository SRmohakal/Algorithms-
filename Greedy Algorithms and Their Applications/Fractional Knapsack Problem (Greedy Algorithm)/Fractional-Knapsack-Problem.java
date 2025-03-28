import java.util.Arrays;
import java.util.Scanner;

class Item {
    int value, weight;

    Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }
}

public class FractionalKnapsack {
    // Comparator for sorting items by value-to-weight ratio
    static void sortItemsByRatio(Item[] items) {
        Arrays.sort(items, (a, b) -> Double.compare((double) b.value / b.weight, (double) a.value / a.weight));
    }

    static double fractionalKnapsack(int capacity, Item[] items) {
        sortItemsByRatio(items); // Sort in descending order
        double totalValue = 0.0;

        for (Item item : items) {
            if (capacity >= item.weight) {
                capacity -= item.weight;
                totalValue += item.value;
            } else {
                totalValue += item.value * ((double) capacity / item.weight);
                break;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = scanner.nextInt();

        Item[] items = new Item[n];
        System.out.println("Enter value and weight for each item:");
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            int weight = scanner.nextInt();
            items[i] = new Item(value, weight);
        }

        System.out.print("Enter knapsack capacity: ");
        int capacity = scanner.nextInt();

        System.out.printf("Maximum value in Knapsack: %.2f%n", fractionalKnapsack(capacity, items));

        scanner.close();
    }
}
