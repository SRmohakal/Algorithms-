#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, weight;
} Item;

// Comparison function for sorting by value/weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double ratio2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    return (ratio2 > ratio1) - (ratio1 > ratio2); // Descending order
}

double fractional_knapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare); // Sort items by value/weight ratio
    double total_value = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum value in Knapsack: %.2f\n", fractional_knapsack(capacity, items, n));
    return 0;
}
