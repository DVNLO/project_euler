fact = 1
for i in range(1, 101):
    fact *= i
digit_sum = 0
while fact > 0:
    digit = fact % 10
    digit_sum += digit;
    fact //= 10
print(str(digit_sum))
