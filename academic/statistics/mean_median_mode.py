from collections import Counter
class Solver(object):
    def findMean(self, data_set):
        mean = sum(data_set) / len(data_set)
        print(mean)

    def findMedian(self, data_set):
        n = len(data_set)
        index = n // 2
        if n % 2:
            median = sorted(data_set)[index]
        else:
            median = sorted(data_set)[index - 1:index + 1]
        print(median)

    def findMode(self, data_set):
        c = Counter(data_set)
        mode = [k for k, v in c.items() if v == c.most_common(1)[0][1]]
        print(mode)

s = Solver()
s.findMean([8,9,13,11,14,16,17,18,19])
s.findMedian([40,60,70,80,1000,120,130,140])
s.findMedian([200,300,400,500,600,700,800,900])
s.findMode([1,2,3,4,5, 5,2,2])