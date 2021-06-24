def bubble_sort(data):
    for i in range(len(data) - 1, -1, -1):
        for j in range(0, (i+1)):
            if data[j] > data[i]:
                tmp = data[i]
                data[i] = data[j]
                data[j] = tmp

    return data


print(bubble_sort([1, 0, 4, 6]))
