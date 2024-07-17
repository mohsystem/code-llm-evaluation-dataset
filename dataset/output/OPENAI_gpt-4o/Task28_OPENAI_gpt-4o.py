def who_likes_it(names):
    count = len(names)

    if count == 0:
        return "no one likes this"
    elif count == 1:
        return "{} likes this".format(names[0])
    elif count == 2:
        return "{} and {} like this".format(names[0], names[1])
    elif count == 3:
        return "{}, {} and {} like this".format(names[0], names[1], names[2])
    else:
        return "{}, {} and {} others like this".format(names[0], names[1], count - 2)

if __name__ == "__main__":
    names = ["Alex", "Jacob", "Mark", "Max"]
    print(who_likes_it(names))