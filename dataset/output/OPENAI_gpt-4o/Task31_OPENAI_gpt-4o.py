def dna_complement(dna):
    complement = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    return ''.join([complement[base] for base in dna])

inputs = ["ATTGC", "GTAT"]
for dna in inputs:
    print(dna_complement(dna))