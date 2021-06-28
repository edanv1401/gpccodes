

public class Main {
	
    static void KMPSearch(String pat, String txt) {
     
            int M = pat.length();
            int N = txt.length();
            
            int lps[] = new int[M];
            int j = 0;
            
            computeLPSArray(pat, M, lps);
            int i = 0;
            while ( i < N){
                if ( pat.charAt(j) == txt.charAt(i)) {
                    i++;
                    j++;
                }
                if (j == M) {
                    System.out.println("Encontrado el patrón en el indice " + (i-j));
                    j = lps[j-1];
                } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                    if ( j != 0){
                        j = lps[j-1];
                    } else {
                        i= i + 1;
                    }
                }
            }
    }
    
    static void computeLPSArray(String pat,int M, int lps[]) {
        int len = 0; 
        int i = 1;
        lps[0] = 0;
        
        while (i<M) {
            if ( pat.charAt(i) ==  pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0 ) {
                    len = lps[len-1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
    
    public static void main (String args[]) {
        String txt = "tinalavalatina";
        String pat = "lati";
        KMPSearch(pat, txt);
    }
    
}
