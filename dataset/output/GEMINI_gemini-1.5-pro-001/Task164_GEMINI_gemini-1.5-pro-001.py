def lastNameLensort(names):
    names.sort(key=lambda x: x.split()[-1])
    names.sort(key=lambda x: len(x.split()[-1]))
    return names