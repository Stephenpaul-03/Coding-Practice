def maxProfit(prices):
    max_profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            max_profit += prices[i] - prices[i - 1]
    return max_profit

t = int(input())
for _ in range(t):
    n = int(input())
    prices = list(map(int, input().split()))
    print(maxProfit(prices))