sum = 0
n = 2**1000
while n > 0:
    d = n % 10
    sum += d
    n //= 10
print(sum)