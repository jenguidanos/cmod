import cmod_conf_defines
import cmod_conf_utils
import copy


def run(conf_base):
    if type(conf_base) is not dict:
        return "ERROR, good bay"

    """ do not mutate original difines dictionary """
    defines = copy.deepcopy(cmod_conf_defines.defines)

    parseDebugConf(conf_base, defines)
    parseGpsConf(conf_base, defines)
    parseMessageConf(conf_base, defines)
    parseNetConf(conf_base, defines)

    return defines


def parseGroup(group, conf, defines):
    """_summary_

    Args:
        group (_type_): _description_
        conf (_type_): _description_
        defines (_type_): _description_
    """
    module = conf["conf"][group]
    print(module)

    if module["enabled"] is not True:
        print("Module" + group + " is disabled")
        return

    if len(module["modules"]) == 0:
        print("Module \"" + group + "\" is enabled but has no modules. Terminating...")
        quit()

    modules = cmod_conf_utils.convertNames(module["modules"], group)
    enabled = "CMOD_" + group.upper() + "_ENABLED"
    default = "CMOD_" + group.upper() + "_DEFAULT"

    defines[enabled] = "1"
    defines[default] = cmod_conf_utils.extractFirst(modules)


def parseDebugConf(conf, defines):
    parseGroup("debug", conf, defines)


def parseGpsConf(conf, defines):
    parseGroup("gps", conf, defines)


def parseMessageConf(conf, defines):
    parseGroup("message", conf, defines)


def parseNetConf(conf, defines):
    parseGroup("net", conf, defines)
