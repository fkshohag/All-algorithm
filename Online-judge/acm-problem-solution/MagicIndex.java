
public class MagicIndex {
	public int search(int []A,int start,int end){
		if(start<=end){
			int mid=(start+end)/2;
			if(mid==A[mid])return mid;
			if(mid>=A[mid]){
				search(A, mid+1, end);
			}
			else{
				search(A, start, mid-1);
			}
		}
		return -1;
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int A[]={-1,0,1,2,4,46,34,5,6};
		MagicIndex m=new MagicIndex();
		System.out.println("Magic Index is:"+m.search(A, 0, A.length-1));
		

	}

}
