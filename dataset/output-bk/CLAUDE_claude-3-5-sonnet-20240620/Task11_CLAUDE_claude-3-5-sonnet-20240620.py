
def nb_year(p0, percent, aug, p):
    years = 0
    population = p0
    
    while population < p:
        population += int(population * percent / 100) + aug
        years += 1
    
    return years

print(nb_year(1500, 5, 100, 5000))
print(nb_year(1500000, 2.5, 10000, 2000000))
