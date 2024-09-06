def dna_strand(dna):
    complement = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    return ''.join(complement[base] for base in dna)

print(dna_strand("ATTGC"))  # Output: TAACG
print(dna_strand("GTAT"))   # Output: CATA