import java.util.*;

public class J1_TwoSum{
	public int[] twoSum(int[] numbers,int target){
		int[] res = new int[2];
		int len = numbers.length;
		Map<Integer,Integer> hashTable = new HashMap<Integer,Integer>(len);

		for(int i=0;i<len;i++){
			int curr = numbers[i],minus = target-curr;

			if(!hashTable.containsKey(curr))
				hashTable.put(curr,i);

			if(hashTable.containsKey(minus)){
				int index2 = hashTable.get(minus);

				if(i != index2){
					res[0] = index2+1;
					res[1] = i+1;

					return res;
				}
			}
		}

		return null;
	}

	public static void main(String[] args){
		int[] numbers = {2,7,9,11};
		int target = 9;

		J1_TwoSum solution = new J1_TwoSum();

		int[] res = solution.twoSum(numbers,target);

		System.out.println(res[0]+" "+res[1]);
	}
}