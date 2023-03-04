import operator
import itertools
import typing

print(operator.add(3, 4))
print(operator.mul(5, 3))
print(operator.sub(5, 2))

_list = [1, 2, 3, 4, 5]

# Summation
result = itertools.accumulate(_list)
for each in result:
    print(each)

# Multiplication
result = itertools.accumulate(_list, operator.mul)
for each in result:
    print(each)

shapes = ['circle', 'triangle', 'square']
result = itertools.permutations(shapes, 3)
for each in result:
    print(each)

# count
for i in itertools.count(0, 2):
    print(i)
    if i >= 20:
        break

# cycle
colors: typing.List[str] = ['red', 'blue', 'green']

count = 0
for color in itertools.cycle(colors):
    print(color)
    if count == 2:
        break
    count += 1

chars = ['a', 'a', 'b', 'b', 'c', 'a']
for key, group in itertools.groupby(chars):
    print(key, ' > ', list(group))

# Permutation
a = ['a', 'b', 'c']
result = itertools.permutations(a)
for each in result:
    print(each)

# product
num_data = [1, 2, 3]
alpha_data = ['a', 'b', 'c']
result = itertools.product(num_data, alpha_data)
for each in result:
    print(each)

