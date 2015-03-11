#include <iostream>


using namespace std;

class Solution{
public:
	 double findMedianSortedArrays(int A[],int m,int B[],int n){
		int size = m+n,target;
		bool isOdd;

		if(size %2 == 0){
			target = size / 2 - 1;
			isOdd = true;
		}else{
			target = size / 2;
			isOdd = false;
		}

		if(m == 0){

			return returnTarget(target,isOdd,B);
			// if(isOdd){
			// 	return (B[target]+B[target+1])/2.0;
			// }else{
			// 	return B[target];
			// }
		}

		if(n == 0){

			return returnTarget(target,isOdd,A);
			// if(isOdd){
			// 	return (A[target]+A[target+1])/2.0;
			// }else{
			// 	return A[target];
			// }
		}

		int indexA=0,indexB=0,k=0;
		int C[size];

		while(indexA < m && indexB < n){
			if(k < size){
				if(A[indexA] <= B[indexB])
					C[k++] = A[indexA++];
				else
					C[k++] = B[indexB++];
			}else
				break;
		}

		while(indexA < m){
			C[k++] = A[indexA++];
		}

		while(indexB < n){
			C[k++] = B[indexB++];
		}

		return returnTarget(target,isOdd,C);

		// if(isOdd){
		// 	return (C[target]+C[target+1])/2.0;
		// }else{
		// 	return C[target];
		// }


	}

	double returnTarget(int target,bool isOdd,int L[]){
		if(isOdd){
			return (L[target] + L[target+1])/2.0;
		}else{
			return L[target];
		}
	}
};

int main(){
	Solution s;
	int A[]={2,3,4,5,6,7,8,9,10},B[]={1};

	double res = s.findMedianSortedArrays(A,9,B,1);

	cout<<res<<endl;

	return 0;
}