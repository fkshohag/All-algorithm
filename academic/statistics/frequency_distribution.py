import pandas as pd
class Solver(object):
    total_frequency = 0
    relative_frequency = dict()
    df = None
    
    def qualitativeFrequencey(self, data_list):
        df = pd.Series(data_list).value_counts().sort_index().reset_index().reset_index(drop=True)
        df.columns = ['value', 'frequency']
        # print(df)
        self.total_frequency = df['frequency'].sum()
        self.df = df

    def getRelativeFrequency(self):
        for index, row in self.df.iterrows():
            self.relative_frequency[row['value']] = row['frequency'] / self.total_frequency
        print(self.relative_frequency)

s = Solver()
s.qualitativeFrequencey([2, 1, 0, 2, 1, 3, 0, 2, 4, 0, 3, 2 ,3, 4, 2, 2, 2, 4, 3, 0])
s.getRelativeFrequency()