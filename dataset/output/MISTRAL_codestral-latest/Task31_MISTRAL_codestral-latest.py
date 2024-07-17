def make_complement(dna):
    result = ""
    for c in dna:
        if c == 'A':
            result += 'T'
        elif c == 'T':
            result += 'A'
        elif c == 'C':
            result += 'G'
        elif c == 'G':
            result += 'C'
    return result