import math
import random
import time
start = time.perf_counter()

#-----------------------------------------

def prime(n):
    if n in {2, 3, 5, 7, 11}:
        return True
    if n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0 or n % 11 == 0:
        return False
    t = 0
    u = n - 1
    while u % 2 == 0:
        t += 1
        u //= 2
    a = random.randint(2, n - 1)
    r = pow(a, u, n)
    if r != 1:
        while t > 1 and r != n - 1:
            r = (r * r) % n
            t -= 1
        if r != n - 1:
            return False
    return True

#-----------------------------------------

def find(n, a):
    def f(x):
        return (x * x + a) % n
    
    if n % 2 == 0:
        return 2
    
    x1 = random.randint(0, n)
    x2 = x1
    while True:
        x1 = f(x1)
        x2 = f(f(x2))
        p = math.gcd(abs(x2-x1), n)
        if p > 1:
            return p
        if x1 == x2:
            return n

#-----------------------------------------
num = int(input('Positive integer:'))
print(f'{num}=')

prime_list = []

while num != 1:
    if prime(num):
        prime_list.append(num)
        break
    else:
        c = find(num, random.randint(0, num-1))
        if prime(c):
            prime_list.append(c)
            num //= c

prime_list.sort()
print('*'.join(map(str, prime_list)))

end = time.process_time()
print(f'Running time: {end - start} Seconds')

