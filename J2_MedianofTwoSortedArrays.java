public class Solution{
	public double findMedianSortedArrays(int A[],int B[]){
		int lenA = A.length, lenB = B.length;
		int size = lenA+lenB, target;
		boolean hasNext;
		int indexA = 0,indexB = 0 ,indexT=0;
		double res;

		if( size %2 == 0){
			target = size / 2 - 1;
			hasNext = true;
		}else{
			target = size /2;
			hasNext = false;
		}

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

		int C[] = new int[target+2];

		while(indexA < lenA && indexB < lenB){
			if(indexT < target+1){
				if(A[indexA] <= B[indexB])
					C[indexT++] = A[indexA++];
				else
					C[indexT++] = B[indexB++];
			}else{
				break;
			}
		}

		while(indexA < lenA){
			if(indexT < target + 1){
				C[indexT++] = A[indexA++];
			}else
				break;
		}

		while(indexB < lenB){
			if(indexT < target + 1){
				C[indexT++] = B[indexB++];
			}else
				break;
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