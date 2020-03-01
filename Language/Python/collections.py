from collections import Counter, defaultdict, OrderedDict

# Python Counter
cnt = Counter()

for word in ['red', 'blue', 'red', 'blue', 'green']:
	cnt[word] += 1

print(cnt)
# Counter({'blue': 2, 'red': 2, 'green': 1})

words = ['red', 'red']

print(Counter(words))

# Counter({'red': 2})


# python Default dict

li = [('red', 2), ('red', 5), ('blue', 6)]
d = defaultdict(list)

for k, v in li:
	d[k].append(v)

print(d)


s = [('red', 1), ('blue', 2), ('red', 3), ('blue', 4), ('red', 1), ('blue', 4)]

d = defaultdict(set)

for k, v in s:
	d[k].add(v)

print(d.items())

# Order dict

d = {'banana': 3, 'apple': 4, 'pear': 1, 'orange': 2}

# dictionary sorted by key
print(OrderedDict(sorted(d.items(), key=lambda t: t[0])))
# OrderedDict([('apple', 4), ('banana', 3), ('orange', 2), ('pear', 1)])

# dictionary sorted by value
print(OrderedDict(sorted(d.items(), key=lambda t: t[1])))
# OrderedDict([('pear', 1), ('orange', 2), ('banana', 3), ('apple', 4)])

# dictionary sorted by length of the key string
print(OrderedDict(sorted(d.items(), key=lambda t: len(t[0]))))
# OrderedDict([('pear', 1), ('apple', 4), ('orange', 2), ('banana', 3)])

