def merge_sorted_arrays(arr1, arr2):
  merged = []
  i = j = 0
  while i < len(arr1) and j < len(arr2):
    if arr1[i] < arr2[j]:
      merged.append(arr1[i])
      i += 1
    else:
      merged.append(arr2[j])
      j += 1
  merged.extend(arr1[i:])
  merged.extend(arr2[j:])
  return merged

if __name__ == "__main__":
  arr1 = [1, 3, 5, 7]
  arr2 = [2, 4, 6, 8]
  merged_array = merge_sorted_arrays(arr1, arr2)
  print(merged_array)