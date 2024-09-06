def last_name_len_sort(names):
    def last_name(name):
        return name.split()[-1]

    names.sort(key=lambda name: (len(last_name(name)), last_name(name)))
    return names