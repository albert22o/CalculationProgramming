import math

with open('angle2.in', 'r') as f:
    x1, y1, x2, y2 = map(float, f.read().split())

dot= x1 * x2 + y1 * y2
normal = math.sqrt(x1**2 + y1**2) * math.sqrt(x2**2 + y2**2)
angle = math.acos(dot / normal)

with open('angle2.out', 'w') as f:
    f.write('%.7f' % angle)