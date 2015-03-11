public class J2_MedianofTwoSortedArrays{
	public double findMedianSortedArrays(int A[],int B[]){
		int lenA = A.length, lenB = B.length;
		int size = lenA+lenB, target;
		boolean hasNext;
		int indexA = 0,indexB = 0 ,indexT=0; 
		double res;

		//判断中位数的位置，标记是否为偶数
		if( size %2 == 0){
			target = size / 2 - 1;
			hasNext = true;
		}else{
			target = size /2; 
			hasNext = false;
		}

		//如果其中一个长度为0直接返回
		if(lenA == 0){
			if(hasNext){
				return (B[target] + B[target + 1])/2.0;
			}else{
				return B[target];
			}
		}

		if(lenB == 0){
			if(hasNext){
				return (A[target] + A[target + 1])/2.0;
			}else{
				return A[target];
			}
		}

		//将数据复制后再从中间查找
		int C[] = new int[size];

		while(indexA < lenA && indexB < lenB){
			if(indexT < size){
				if(A[indexA] <= B[indexB])
					C[indexT++] = A[indexA++];
				else
					C[indexT++] = B[indexB++];
			}else{
				break;
			}
		}

		while(indexA < lenA){
				C[indexT++] = A[indexA++];
		}

		while(indexB < lenB){
				C[indexT++] = B[indexB++];
		}

		if(hasNext){
			res = (C[target]+C[target + 1]) / 2.0;
		}else{
			res = C[target];
		}

		return res;

	}

	// public static void main(String[] args){

	// }
}