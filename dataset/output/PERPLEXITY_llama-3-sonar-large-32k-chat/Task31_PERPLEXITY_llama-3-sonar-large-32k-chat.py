def DNATranslate(dna):
    complement = ""
    for c in dna:
        if c == 'A':
            complement += 'T'
        elif c == 'T':
            complement += 'A'
        elif c == 'C':
            complement += 'G'
        elif c == 'G':
            complement += 'C'
    return complement

print(DNATranslate("ATTGC")) # --> "TAACG"
print(DNATranslate("GTAT")) # --> "CATA"