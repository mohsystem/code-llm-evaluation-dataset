def lastNameLensort(names):
    return sorted(names, key=lambda x: (len(x.split()[-1]), x.split()[-1]))