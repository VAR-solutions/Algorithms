function fibonacci_search(arr, x, n)
	local fib2 = 0
	local fib1 = 1
	local fibM = fib2 + fib1
	while fibM < n do
		fib2 = fib1
		fib1 = fibM
		fibM = fib2 + fib1
	end

	local offset = -1

	while fibM > 1 do
		local i = math.min(offset + fib2, n - 1)

		if arr[i] < x then
			fibM = fib1
			fib1 = fib2
			fib2 = fibM - fib1
			offset = i
		elseif (arr[i] > x) then
			fibM = fib2
			fib1 = fib1 - fib2
			fib2 = fibM - fib1
		else 
			return i
		end
	end

	if fib1 == 1 and arr[offset + 1] == x then
		return offset + 1
	end

	return - 1
end

--test
arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100}
x = 85 
n = 11 --array lenght
print("values: 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100")
print("wanted value: " .. x )
print("value found at index: " .. fibonacci_search(arr, x, n))
