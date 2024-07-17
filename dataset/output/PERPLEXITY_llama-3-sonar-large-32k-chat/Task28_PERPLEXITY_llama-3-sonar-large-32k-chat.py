def who_likes_it(names):
    if len(names) == 0: return "no one likes this"
    if len(names) == 1: return names[0] + " likes this"
    if len(names) == 2: return names[0] + " and " + names[1] + " like this"
    if len(names) == 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this"
    return names[0] + ", " + names[1] + " and " + str(len(names) - 2) + " others like this"

print(who_likes_it([]))
print(who_likes_it(["Peter"]))
print(who_likes_it(["Jacob", "Alex"]))
print(who_likes_it(["Max", "John", "Mark"]))
print(who_likes_it(["Alex", "Jacob", "Mark", "Max"]))