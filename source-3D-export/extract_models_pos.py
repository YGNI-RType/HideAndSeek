from PyVMF import *
import os

###
import numpy as np
from scipy.spatial.transform import Rotation as R
import sys
###

knowModels = {}

if len(sys.argv) < 3:
    print("Usage: extract_pos.py <vmf_file> <export_infos_path>")
    sys.exit(1)

vmf_file = sys.argv[1]
exportPath = sys.argv[2]

v = load_vmf(vmf_file)
exportPath = exportPath

def createNewPropInfo(name, model, origin, angle, knowModels):
    with open(os.path.join(exportPath, f"{name}.{knowModels[model]:03d}.info"), 'w') as f:
        f.write(f"{angle}\n")
        f.write(f"{origin}\n")

for s in v.entity:
    if not s.classname.startswith("prop_"):
        continue

    model = ""
    if not hasattr(s, "model"):
        if "model" not in s.other:
            continue
        model = s.other["model"]
        refAnge = s.other["angles"]
        origin = s.other["origin"]
        de = [float(x) for x in refAnge.split(' ')]
        refAnge = Vertex(de[0], de[1], de[2])
    else:
        model = s.model
        refAnge = s.angles
        origin = s.origin

    if len(model) == 0:
        continue

    if model in knowModels:
        createNewPropInfo(name, model, origin, refAnge, knowModels)
        knowModels[model] += 1
        continue

    knowModels[model] = 1
    name = os.path.splitext(os.path.basename(os.path.normpath(model)))[0]
    angle = Vertex(-refAnge.z, -refAnge.x, -refAnge.y)
    with open(os.path.join(exportPath, f"{name}.info"), "w") as f:
        f.write(f"{angle}\n")
    createNewPropInfo(name, model, origin, refAnge, knowModels)
    knowModels[model] += 1
