class Binary_Search:
	def Insertion_sort(self,array):         
		for i in range(0,len(array)):
			j=i
			while j>0 and array[i]<array[j-1]:
				j=j-1
			temp=array[i]
			for k in xrange(i,j,-1):
				array[k]=array[k-1]
			array[j]=temp
	def Bubble_sort(self,array):          
		for i in xrange(0,len(array)):
			for j in xrange(0,len(array)-1):
				if array[j]>array[j+1]:
					temp=array[j]
					array[j]=array[j+1]
					array[j+1]=temp
	def De_bubble_sort(self,array):          
		for i in xrange(0,len(array)):
			for j in xrange(0,len(array)-1):
				if array[j]<array[j+1]:
					temp=array[j]
					array[j]=array[j+1]
					array[j+1]=temp
	def binary_search(self,array,key):        
		Index=None
		begin=0
		End=len(array)
		while begin<=End:
			mid=(begin+End)/2
			if key==array[mid]:
				Index=mid
				break
			elif key>array[mid]:
				begin=mid+1
			elif key<array[mid]:
				End=mid-1
		return Index
	def binary_searchLeftIndex(self,array,key):
		Index=None
		begin=0
		End=len(array)
		while begin<=End:
			mid=(begin+End)/2
			if key==array[mid]:
				Index=mid
				End=mid-1
			elif key>array[mid]:
				begin=mid+1
			elif key<array[mid]:
				End=mid-1
		return Index
	def binary_searchRigtIndex(self,array,key):
		Index=None
		begin=0
		End=len(array)
		while begin<=End:
			mid=(begin+End)/2
			if key==array[mid]:
				Index=mid
				begin=mid+1
			elif key>array[mid]:
				begin=mid+1
			elif key<array[mid]:
				End=mid-1
		return Index
	def lower_bondIndex(self,array,key):
		Index=None
		begin=0
		End=len(array)-1
		while begin<=End:
			mid=(begin+End)/2
			if key==array[mid]:
				Index=mid
				End=mid-1
			elif key>array[mid]:
				begin=mid+1
			elif key<array[mid]:
				End=mid-1
		return begin
	def isRange(self,array,key):
		Len=len(array)
		Len=Len-1
		if key>array[Len]:
			return 0
		elif key<array[0]:
			return 0
		else:
			return 1
	def upper_bondIndex(self,array,key):
		Index=None
		begin=0
		End=len(array)
		while begin<=End:
			mid=(begin+End)/2
			if key==array[mid]:
				Index=mid
				begin=mid+1
			elif key>array[mid]:
				begin=mid+1
			elif key<array[mid]:
				End=mid-1
		return End+1
	def Sqrt(self,x): 
		low=0.0
		high=x
		while high-low>.00000000000001:
			mid=(low+high)/2
			if mid*mid>x:
				high=mid;
			else:
				low=mid
		return mid
b=Binary_Search()
print(b.Sqrt(15))
