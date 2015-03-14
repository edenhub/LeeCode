import java.util.*;

public class J6_ZigZagConversion {
    public String convert(String s, int nRows) {
        StringBuffer sb = new StringBuffer();

        int len = s.length(), m;

        if(len == 0){
            return "";
        }

        if(nRows == 1){
            return s;
        }

        int r = nRows, chunk = 2*r - 2;

        if(len % chunk == 0)
            m = len / chunk;
        else
            m = len / chunk + 1;

        m *= 2;

        int[] flags = new int[m+1]; 
        for(int i=0;i<=m; i+=2){
            int position = i/2 * chunk; 
            flags[i] = position;
            
            if(isPositionOk(position,len)){
                sb.append(s.charAt(position));
            }
        }

        // System.out.println(Arrays.toString(flags));

        for(int i=1;i<r-1;i++){
                if(i == 1){
                    for(int j=0;j<=m;j+=2){
                            int position = flags[j] + 1;
                            flags[j] = position;
                            if(isPositionOk(position,len)){
                                sb.append(s.charAt(position));
                            }

                            if(j+2 <= m){
                                position = flags[j+2] - 1;
                                flags[j+1] = position;
                                if(isPositionOk(position,len)){
                                    sb.append(s.charAt(position));
                                }
                            }
                    }
                }else{
                    for(int j=0;j<=m;j++){
                    if(j % 2 == 0){
                            flags[j] = flags[j] + 1;
                        if(isPositionOk(flags[j],len)){
                            sb.append(s.charAt(flags[j]));
                        }
                    }else{
                            flags[j] = flags[j] - 1;
                        if(isPositionOk(flags[j],len)){
                            sb.append(s.charAt(flags[j]));
                        }
                    }
                }
            }

                // System.out.println(Arrays.toString(flags));
        }

        for(int i=0;i<=m;i+=2){
            int position = flags[i] + 1;
                flags[i] = position;
            if(position < len){
                sb.append(s.charAt(position));
            }
        }

        // System.out.println(Arrays.toString(flags));

        

        return sb.toString();
    }

    public boolean isPositionOk(int position,int bound){
        if(position < bound && position>=0)
            return true;

        return false;
    }

    public static void main(String[] args){
    	J6_ZigZagConversion solution = 
    		new J6_ZigZagConversion();

    	System.out.println(solution.convert("txkrsdyronxiisbacxkdczwdlevfughpftgxzhpnuoxegagixsnbujffpcmkivbpoimnrddnrcuzdakatxcnjjsangmxbomryahpekexmyzrzjsuiwjrfduujgrkuddsfkjjwqjjoiaptulbquvxxprgvksqnwktiwefmpqczsusnfufarfxgygbjatywgthcamqpcsrumjjufpuwwteubifcbeajzhnzvdrxyismtdgbscxqyclzksdnwgzypmxlsqisaceuglvapurnyepkwuavaztqnsbhjlzjoefurcwgznwxtliqfklileyywbihmhtanywebvnakjzewjudthlenlflontbumdimcopxbrhmrlkahqwqdafphrfumgrakzmmpclttshmgsnpilgllncteipqqgschfoxjbqcuzrcrerbrzpcnrxtbpmsveudjlcsmuxitoknueonfdpsxpmaeyubepgociiqehbyxlltrbgxfypepdevdzwiqdyungksqlqnzdjqepnlpfrekwzoxwynbwjqetiuhakidtykkoxavpefngvketzfpivudgqkgasmvtygjxiemmjzuhlyakfsudoyjekrhffcydkjbsnphyrdfcciphajkojvsunbzsezyqiblvquvjxbobjdjjovzyrruettyzswraxexqyszyvnzgsirjeqjxkdbfwzeqyxqxcpnchpafcclxkdgqtpndsqkqsqgqoynsnduwsxbwznvlsbensttmkdceukuiijaxowugtxfukageeksydllpontiansizuinrcwmbdhofnslzkkcvvsmknukdpvcjdrchppiuyyalrlmbxqzsilfyhpbwmdgrwiaozjixhikawwctndoxotvvkwsxbaoyipmiaufjfqmdooybtmzhfwestwpuwfuhwi",926));
    }
}