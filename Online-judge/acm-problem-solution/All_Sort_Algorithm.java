public class Sort{
	public void Bubble_sort(int data[])
	{
		for(int i=0;i<data.length;i++)
			for(int j=0;j<data.length-1;j++)
				if(data[j]>data[j+1])
				{
					int temp=data[j];
					data[j]=data[j+1];
					data[j+1]=temp;
				}
	}
	public void Insertion_sort(int data[])
	{
		for(int i=0;i<data.length;i++)
		{
			int j=i;
			while(j>0 && data[i]<data[j-1])
				j--;
			int temp=data[i];
			for(int k=i;k>j;k--)
				data[k]=data[k-1];
			data[j]=temp;
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int data[]={3,4,5,3,4,5,34,3,4343,45,454,60,0,0,1,0,100,2100,2};
		Sort a=new Sort();
		a.Insertion_sort(data);
		for(int i=0;i<data.length;i++)
			System.out.printf("%d ",data[i]);

	}

}
