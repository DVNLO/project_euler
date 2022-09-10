def digit_count(n):
    if not n:
        return 1
    if n < 0:
        n += 2 * n
    ret = 0  # digit count
    while n > 0:
        ret += 1
        n //= 10
    return ret


pre = 1  # F_1
cur = 1  # F_2
i = 2
dc = 1
while dc < 1000:
    nxt = pre + cur
    dc = digit_count(nxt)
    pre = cur
    cur = nxt
    i += 1
print(str(i))
