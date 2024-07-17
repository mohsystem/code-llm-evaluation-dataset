def make_complement(dna: str) -> str:
  """
  This function takes a DNA strand as input and returns its complement.

  Args:
    dna: The DNA strand to be complemented.

  Returns:
    The complement of the input DNA strand.
  """
  complement = ''
  for nucleotide in dna:
    if nucleotide == 'A':
      complement += 'T'
    elif nucleotide == 'T':
      complement += 'A'
    elif nucleotide == 'C':
      complement += 'G'
    elif nucleotide == 'G':
      complement += 'C'
    else:
      complement += '?'  
  return complement


if __name__ == "__main__":
  dna_strand = input("Enter DNA strand: ")
  print(make_complement(dna_strand))