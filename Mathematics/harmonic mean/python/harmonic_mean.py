def harmonic(a, b):
    return (2*a*b)/(a + b);

a, b = map(int, input().split())
print(harmonic(a, b))
