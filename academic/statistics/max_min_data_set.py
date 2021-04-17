class Solver(object):
    def findMin(self, data_set):
        return (data_set)

    def findMax(self, data_set):
        return max(data_set)
    
    def sortedData(self, data_set):
        return data_set.sorted()

s = Solver()
data_set = []
mi = s.findMin(data_set)
mx = s.findMax(data_set)
data_set = s.sortedData(data_set)
print(mi, mx, data_set)