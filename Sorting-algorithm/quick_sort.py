class QuickSort:
	def partition(self, data , left, right):
		counter, pivot = left-1, data[right-1]
		for i in range(left, right):
			if data[i] < pivot:
				counter += 1
				data[counter], data[i] = data[i], data[counter]
		data[counter+1], data[right-1] = data[right-1], data[counter+1]
		return counter+1, data
			

	def qsort(self, data, left, right):
		if left < right:
			mid, data = self.partition(data, left, right)
			self.qsort(data, left, mid-1)
			self.qsort(data, mid+1, right)
		return data

s = QuickSort()
lis = [3,4,5,2,4]
li = s.qsort(lis, 0, len(lis))
print(li)
