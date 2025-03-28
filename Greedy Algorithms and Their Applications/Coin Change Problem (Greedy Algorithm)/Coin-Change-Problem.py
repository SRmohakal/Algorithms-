def greedy_coin_change(denominations, amount):
    denominations.sort(reverse=True) 
    ans = []
    
    for coin in denominations:
        while amount >= coin:
            amount -= coin
            ans.append(coin)
    
    return ans

if __name__ == "__main__":
    denominations = [int(x) for x in input("Enter the denominations: ").split()]
    amount = int(input("Enter the amount: "))
    
    print("Coins used:", greedy_coin_change(denominations, amount))
