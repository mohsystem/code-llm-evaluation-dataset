def tweakLetters(txt, arr):
  res = []
  for i in range(len(txt)):
    if arr[i] == 1:
      res.append(chr(ord(txt[i])+1))
    elif arr[i] == -1:
      res.append(chr(ord(txt[i])-1))
    else:
      res.append(txt[i])
  return ''.join(res)