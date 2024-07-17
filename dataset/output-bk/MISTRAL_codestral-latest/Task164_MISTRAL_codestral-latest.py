def last_name_len_sort(names):
    return sorted(names, key=lambda x: (len(x.split()[-1]), x.split()[-1]))