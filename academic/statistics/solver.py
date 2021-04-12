import pandas as pd

class Solver(object):
    def qualitativeFrequencey(self, data_list):
        df1 = pd.Series(data_list).value_counts().sort_index().reset_index().reset_index(drop=True)
        df1.columns = ['value', 'Frequency']
        print(df1)

s = Solver()
s.qualitativeFrequencey([2, 1, 0, 2, 1, 3, 0, 2, 4, 0, 3, 2 ,3, 4, 2, 2, 2, 4, 3, 0])