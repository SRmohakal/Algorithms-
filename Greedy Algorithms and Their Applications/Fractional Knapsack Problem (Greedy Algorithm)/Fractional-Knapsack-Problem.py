class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

def fractional_knapsack(capacity, items):
    # Sort items based on value-to-weight ratio (descending order)
    items.sort(key=lambda x: x.value / x.weight, reverse=True)

    total = 0
    for item in items:
        if capacity >= item.weight:
            capacity -= item.weight
            total += item.value
        else:
            fraction = capacity / item.weight
            total += item.value * fraction
            break  # Knapsack is full

    return total

if __name__=="__main__":
    n = int(input("Enter the number of items: "))
    items = []

    print("Enter the value and weight for each item: ")
    for i in range(n):
        value, weight = map(int, input().split())
        items.append(Item(value, weight))

    capacity = int(input("Enter the Knapsack capacity: "))
    print("Maximum value is: ", fractional_knapsack(capacity, items))
