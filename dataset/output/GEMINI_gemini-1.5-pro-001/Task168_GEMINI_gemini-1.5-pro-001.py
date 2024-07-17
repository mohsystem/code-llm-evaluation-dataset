def tweakLetters(txt, arr):
  newTxt = ""
  for i in range(len(txt)):
    if arr[i] == 1:
      newTxt += chr(ord(txt[i]) + 1)
    elif arr[i] == -1:
      newTxt += chr(ord(txt[i]) - 1)
    else:
      newTxt += txt[i]
  return newTxt