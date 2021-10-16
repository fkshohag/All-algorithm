import numpy as np

x1 = [0, 0, 1, 1]
x2 = [0, 1, 0, 1]
yd = [0, 1, 1, 1]

errors = [None, None, None, None]

w1 = 0.4
w2 = 0.1
th = 0.2

lr = 0.1

def checkForError(listOfErrors):
    for element in listOfErrors:
        if element != 0:
            return False
    return True

def setp(yp):
    return 1 if yp > 0 else 0

epoch = 1

while True:
    for i in range(4):
        yp = x1[i] * w1 + x2[i] * w2 - th
        yp = setp(yp)
        errors[i] = yd[i] - yp

        w1 += lr * x1[i] * errors[i]
        w2 += lr * x2[i] * errors[i]

    result = checkForError(errors)

    if result is True:
        break
    epoch += 1

print("epoch= ", epoch, "and weight w1 = ", w1, "w2 =", w2)
