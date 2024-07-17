def nbYear(p0, percent, aug, p):
    years = 0
    while p0 < p:
        p0 += int(p0 * (percent / 100)) + aug
        years += 1
    return years

print(nbYear(1500, 5, 100, 5000))
print(nbYear(1500000, 2.5, 10000, 2000000))