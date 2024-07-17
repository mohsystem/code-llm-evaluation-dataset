def validatePin(pin):
    if len(pin) == 4 or len(pin) == 6:
        for c in pin:
            if not c.isdigit():
                return False
        return True
    return False

print(validatePin("1234")) # True
print(validatePin("12345")) # False
print(validatePin("a234")) # False