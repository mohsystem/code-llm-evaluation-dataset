def find_nb(m):
    n = 0
    volume = 0
    
    while volume < m:
        n += 1
        volume += n**3
    
    if volume == m:
        return n
    else:
        return -1

print(find_nb(1071225))  # 45
print(find_nb(91716553919377))  # -1