import cmod_conf_map
import cmod_conf_reduce
import cmod_conf_finally

def main():
    """ define vars """
    conf = {}
    conf_base = {}

    """ load json file from disk """
    conf_base = cmod_conf_map.run()

    """ Parse and create and object conf suitable for finally """
    conf = cmod_conf_reduce.run(conf_base)

    """ save results, generate code """
    cmod_conf_finally.run(conf)

if __name__ == "__main__":
    main()
