
public class J5_LongestPalindromicSubstring{
	public String longestPalindrome(String s) {
        int len = s.length();
        if(len == 0)
        	return "";

        String longest = s.substring(0,1);

        for(int i=0;i<len-1;i++){
        	String p1 = expandAroundCenter(s,i,i);
        	if(p1.length() > longest.length()){
        		longest = p1;
        	}
        	String p2 = expandAroundCenter(s,i,i+1);
        	if(p2.length() > longest.length()){
        		longest = p2;
        	}
        }

        return longest;
    }

    public String expandAroundCenter(String str,int l,int r){
    	int len = str.length();

    	while(l >= 0 && r <= len-1 && str.charAt(l) == str.charAt(r)){
    		l--;
    		r++;
    	}

    	return str.substring(l+1,r);
    }

    public static void main(String[] args){
    	J5_LongestPalindromicSubstring solution = new J5_LongestPalindromicSubstring();
    	System.out.println(solution.longestPalindrome("abacdfgdcaba"));
    }
}