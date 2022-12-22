import json

jsonPath = "cmod-conf-base.json"

def run():
    data = {}
    try:
        f = open(jsonPath)
        data = json.load(f)
        f.close()
    except FileNotFoundError as e:
        print("ERROR loading JSON config file")
        data = None

    return data
