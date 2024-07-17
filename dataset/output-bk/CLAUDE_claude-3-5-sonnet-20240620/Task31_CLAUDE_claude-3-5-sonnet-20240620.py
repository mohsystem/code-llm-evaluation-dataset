
def DNA_strand(dna):
    complement = {\'A\': \'T\', \'T\': \'A\', \'C\': \'G\', \'G\': \'C\'}
    return \'\'.join(complement[c] for c in dna)

print(DNA_strand("ATTGC"))  # Output: TAACG
print(DNA_strand("GTAT"))   # Output: CATA
