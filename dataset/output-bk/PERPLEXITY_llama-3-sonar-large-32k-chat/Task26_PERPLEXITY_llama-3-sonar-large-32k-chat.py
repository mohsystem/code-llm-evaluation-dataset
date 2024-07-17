def find_odd(seq):
    for i in seq:
        if seq.count(i) % 2 != 0:
            return i

seq = [1,2,2,3,3,3,4,3,3,3,2,2,1]
result = find_odd(seq)
print(result)