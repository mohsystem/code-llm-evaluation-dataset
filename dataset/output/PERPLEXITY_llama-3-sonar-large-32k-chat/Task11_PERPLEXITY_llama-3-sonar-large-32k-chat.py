def nb_year(p0, percent, aug, p):
    years = 0
    while p0 < p:
        p0 += int(p0 * (percent / 100)) + aug
        years += 1
    return years