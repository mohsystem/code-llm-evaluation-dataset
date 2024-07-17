def validate_pin(pin):
    if len(pin) != 4 and len(pin) != 6:
        return False
    for i in pin:
        if not i.isdigit():
            return False
    return True

if __name__ == "__main__":
    print(validate_pin("1234"))
    print(validate_pin("12345"))
    print(validate_pin("a234"))