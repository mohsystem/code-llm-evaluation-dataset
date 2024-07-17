people = [[10, 0], [3, 5], [5, 8]]
remaining_people = 0
for pair in people:
    remaining_people += pair[0] - pair[1]
print(remaining_people)