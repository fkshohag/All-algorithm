class Solver(object):
    def findMin(self, data_set):
            print(min(data_set))

    def findMax(self, data_set):
        print(max(data_set))
    
    def sortedData(self, data_set):
        x = sorted(data_set)
        print(x)

s = Solver()
data_set = [8, 25, 11, 15, 29, 22, 10, 5, 17, 21,
22, 13, 26, 16, 20, 12, 9, 26, 20, 16,
23, 14, 19, 23, 20, 16, 27, 16, 21, 14]
s.findMin(data_set)
s.findMax(data_set)
s.sortedData(data_set)
