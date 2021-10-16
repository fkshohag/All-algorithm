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

print("ep", "x1", "x2", "yd", "w1", "w2", "yp", 'er', "w1", "w2")
print("\n")

while True:
    for i in range(4):
        yp = x1[i] * w1 + x2[i] * w2 - th
        yp = setp(yp)
        errors[i] = yd[i] - yp
        w1i = w1
        w2i = w2

        w1 += lr * x1[i] * errors[i]
        w2 += lr * x2[i] * errors[i]

        print(epoch, x1[i], x2[i], yd[i], round(w1i, 2), round(w2i, 2), round(yp, 2), errors[i] ,round(w1, 2),  round(w2, 2))

    result = checkForError(errors)

    if result is True:
        break
    epoch += 1
    print("\n")
