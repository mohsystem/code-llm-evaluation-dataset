def DNA_strand(dna):
    return dna.translate(str.maketrans("ATCG", "TAGC"))