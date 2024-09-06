def findNb(m):
    n, total_volume = 0, 0
    while total_volume < m:
        n += 1
        total_volume += n ** 3
    return n if total_volume == m else -1

print(findNb(1071225))  # 45
print(findNb(91716553919377))  # -1