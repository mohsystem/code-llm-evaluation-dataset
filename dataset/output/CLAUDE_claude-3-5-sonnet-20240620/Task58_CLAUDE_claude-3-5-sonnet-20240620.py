
def getXO(string):
    string = string.lower()
    return string.count(\'x\') == string.count(\'o\')

print(getXO("ooxx"))
print(getXO("xooxx"))
print(getXO("ooxXm"))
print(getXO("zpzpzpp"))
print(getXO("zzoo"))
