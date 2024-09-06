def DNA_strand(dna):
    complements = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    return ''.join([complements[char] for char in dna])