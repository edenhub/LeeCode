/*
大数相加
*/

public class J4_AddTwoNumber{
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode n1=l1,n2=l2,idx3=new ListNode(-1),taile = idx3;
        int add=0;

        while(n1!=null && n2 != null){
        	int v1 = n1.val,v2 = n2.val;
        	int v,total = v1 + v2 + add;

        	if(total > 9){
        		v = total - 10;
        		add = total / 10;
        	}else{
        		v = total;
        		add = 0;
        	}

        	ListNode l = new ListNode(v);
        	taile.next = l;
        	taile = l;
        	

        	n1 = n1.next;
        	n2 = n2.next;
        }

        while(n1!=null){
        	int v1 = n1.val;
        	int v,total = v1 + add;

        	if(total > 9){
        		v = total - 10;
        		add = total / 10;
        	}else{
        		v = total;
        		add = 0;
        	}

        	ListNode l = new ListNode(v);
        	taile.next = l;
        	taile = l;

        	n1 = n1.next;
        }

        while(n2!=null){
        	int v2 = n2.val;
        	int v,total = v2 + add;

        	if(total > 9){
        		v = total - 10;
        		add = total / 10;
        	}else{
        		v = total;
        		add = 0;
        	}

        	ListNode l = new ListNode(v);
        	taile.next = l;
        	taile = l;

        	n2 = n2.next;
        }

        if(add != 0){
        	ListNode l = new ListNode(add);
        	taile.next = l;
        	taile = l;
        }

        return idx3.next;
    }

    public static void main(String[] args){

    }

    public static class ListNode {
     int val;
     ListNode next;
     ListNode(int x) {
          val = x;
          next = null;
      }
 	}
}