import java.util.*;

public class J3_LongestSubstring{

	public int lengthOfLongestSubstring(String s){
		int len = s.length(),max = 0;

		int[] locs = new int[256];

		for(int i=0;i<locs.length;i++){
			locs[i] = -1;
		}

		int idx = -1;

		for(int i=0;i<len;i++){
			if(locs[s.charAt(i)] > idx){
				idx = locs[s.charAt(i)];
			}

			if (i - idx > max) {
				max = i - idx;
			}

			locs[s.charAt(i)] = i;
		}


		return max;
	}

	public int lengthOfLongestSubstring_2(String s){
		int len = s.length(),max=0;

		for(int i=0;i<len-max;i++){ 
			Set<Character> ctn = new HashSet<Character>(len-max);
			for(int j=i;j<len;j++){
				char ch = s.charAt(j);
				if(!ctn.contains(ch)){
					ctn.add(ch);
				}else{
					int size = ctn.size();
					if(max < size) max = size;
					break;
				}
			}
		}

		return max;
	}

	public static void main(String[] args){
		J3_LongestSubstring sb = new J3_LongestSubstring();
		int res = sb.lengthOfLongestSubstring("abcabcbb");
		System.out.println(res);
	}
}