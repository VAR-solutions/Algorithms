class CoinChange:

	LENGTH = 15;

	def __init__(self, coins):
		self.coins = coins
		self.memo = [[-1 for x in range(15)] for x in range(15)]

	def start(self, current_index, current_value):
		if current_index >= len(self.coins) or current_value < 0:
			return 0

		if current_value == 0:
			return 1

		if self.memo[current_index][current_value] != -1:
			return self.memo[current_index][current_value]

		total_ways = 0
		total_ways += self.start(current_index, current_value - self.coins[current_index])
		total_ways += self.start(current_index + 1, current_value)
		self.memo[current_index][current_value] = total_ways
		return total_ways

coin_change_calculator = CoinChange([2, 3, 5])
print(coin_change_calculator.start(0, 7))