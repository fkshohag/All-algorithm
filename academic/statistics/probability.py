list_of_days = [2, 1, 0, 2, 1, 3, 0, 2, 4, 0, 3, 2 ,3, 4, 2, 2, 2, 4, 3, 0] # created a list of the data
import pandas as pd

df1 = pd.Series(list_of_days).value_counts().sort_index().reset_index().reset_index(drop=True)
df1.columns = ['Demand', 'Frequency']
print(df1)