from multiprocessing.dummy import Array
import string


def extractFirst(data):
    print(data)
    if type(data) is string:
        return data
    if type(data) is list:
        if len(data) == 0:
            raise Exception("A value array is empty and requires at least one value")
        else:
            return data[0]
    else:
        print(type(data))
        raise Exception("expected a string or an array")

def _convertName(name, group):
    return "CMOD_" + group.upper() + "_" + name.upper()

def convertNames(names, group):
    return list(map(lambda x: _convertName(x, group), names))
