import random

# Generate a random integer between 1 and 10
random_integer = random.randint(1, 10)
print("Random Integer:", random_integer)

# Generate a random floating-point number between 0 and 1
random_float = random.random()
print("Random Float:", random_float)

# Generate a random element from a list
my_list = ["apple", "banana", "cherry"]
random_element = random.choice(my_list)
print("Random Element:", random_element)

# Generate a random sample of 2 elements from a list
random_sample = random.sample(my_list, 2)
print("Random Sample:", random_sample)