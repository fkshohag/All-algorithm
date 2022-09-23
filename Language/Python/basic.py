print("Hello man")


def area(x, y=3.4):
    return x * x * y


def findNumber(x):
    if x < 10:
        print("less then 10")
    elif x > 10:
        print("greater then 10")
    else:
        print("unknown")


def errorHandle():
    try:
        x = 10 / 0
    except ArithmeticError:
        print("divide with zero not possible")
    finally:
        print('error out from the exception')


def dataTypeDeclare():
    a = b = c = 1
    print(a, b, c)
    a, b, c = 4, 3, "love"
    print(a, b, c)
    del c, a  # deleting data

    s = "I love bangladesh"
    print(s)
    print(s[0])
    print(s[2:5])
    print(s[2:])
    print(s*2)
    print(s + "test")


def listManipulation():
    li = [2, 4, 45, 'kabir']
    li.append(34)  # append after last element
    li.extend([3, 4])
    li.insert(0, 67)
    del li[1:3]
    li2 = [3, 45, 5, 6]
    print(li)
    print(li[1:3])
    print(li[1:])
    print(li + li2)


def tupleManipulation():
    t = (1, 3, 4)
    t2 = (4, 3, 5)
    print(t)
    print(t[:2])
    print(1, 2)
    print(t + t2)


def dictManipulation():
    dict = {}
    dict['name'] = 'shohag'
    dict['roll'] = 344
    print(dict)

    tinydict = {'name': 'kabir', 'code': 3453, 'dept': 'sales'}
    print(tinydict)
    print(tinydict.keys())
    print(tinydict.values())


def loopManipulation():
    li = [3, 4, 45, 4, 5]
    # li.sort()
    # li.reverse()

    for x in li:
        print(x)

    dict = {
        'name': 'shohag',
        'roll': 34453,
        'id': 201900010038
    }
    values = dict.values()  # ['shohag', 34453, 201900010038]
    keys = dict.keys()  # ['name', 'roll', 'id']
    items = dict.items()  # [('name', 'shohag'), ('roll', 34453), ('id', 201900010038)]

    for key in dict:  # key is the dict key
        print(dict[key])
    for key, value in dict.items():  # key and value (key, value)
        print(key, '->', value)

    # while loop
    index = 1
    print('\nwhile loop started')
    while index < 10:
        print(index)
        index += 1

    print('\nfor loop started')
    for index in range(0, len(li), 1):
        print(li[index])


if __name__ == '__main__':
    print(area(3))
    findNumber(33)
    errorHandle()
    dataTypeDeclare()
    listManipulation()
    tupleManipulation()
    dictManipulation()
    loopManipulation()
