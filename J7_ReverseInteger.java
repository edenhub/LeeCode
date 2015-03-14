public class J7_ReverseInteger{
	public int reverse(int x) {
		if(x == 0)
			return 0;
		boolean isNegetive = (x < 0) ? true : false;
		if(isNegetive) x = -x;
        return 0;
    }

    public static void main(String[] args){
    	System.out.println(String.valueOf("-12"));
    	System.out.println(Integer.MAX_VALUE);
    	System.out.println(Integer.MIN_VALUE);
    }
}