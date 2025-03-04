import random

def fusion(g: list, d: list):
    to_return = []
    while len(g) > 0 and len(d) > 0:
        if g[0] < d[0]: to_return.append(g.pop(0))
        else: to_return.append(d.pop(0))

    if len(g) <= 0:
        for e in d: to_return.append(e)
    if len(d) <= 0:
        for e in g: to_return.append(e)
    
    return to_return

def tri_fusion(l: list):
    g = l[:len(l)//2]
    d = l[len(l)//2:]
    if len(g) > 1: g = tri_fusion(g)
    if len(d) > 1: d = tri_fusion(d)

    return fusion(g, d)

print(tri_fusion([random.randint(0, 100) for i in range(50)]))