import math

with open('angle1.in', 'r') as f:
    x, y = map(int, f.readline().split())

if x == 0:
    if y > 0:
        angle = math.pi / 2
    else:
        angle = 3 * math.pi / 2
else:
    angle = math.acos(x / math.sqrt(x**2 + y**2))
    if y < 0:
        angle = 2 * math.pi - angle

with open('angle1.out', 'w') as f:
    f.write(str(angle))