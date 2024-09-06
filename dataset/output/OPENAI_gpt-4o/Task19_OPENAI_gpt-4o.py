def spin_words(sentence):
    return ' '.join(word if len(word) < 5 else word[::-1] for word in sentence.split())

if __name__ == "__main__":
    examples = ["Hey fellow warriors", "This is a test", "This is another test"]
    for example in examples:
        print(spin_words(example))