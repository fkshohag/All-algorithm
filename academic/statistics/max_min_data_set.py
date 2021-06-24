class Solver(object):
    def findMin(self, data_set):
            print(min(data_set))

    def findMax(self, data_set):
        print(max(data_set))
    
    def sortedData(self, data_set):
        x = sorted(data_set)
        print(x)

s = Solver()
data_set = [200,300,400,500,600,700,800,900]
s.findMin(data_set)
s.findMax(data_set)
s.sortedData(data_set)
