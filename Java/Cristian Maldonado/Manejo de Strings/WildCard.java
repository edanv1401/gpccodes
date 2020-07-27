import java.util.Arrays;

public class WildCard {

    static boolean strMatch(String str, String pattern, int n, int m) {
        if (m == 0) {
            return n == 0;
        }
        boolean[][] lookup = new boolean[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(lookup[i], false);
        }
        lookup[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (pattern.charAt(j - 1) == '*') {
                lookup[0][j] = lookup[0][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern.charAt(j - 1) == '*') {
                    lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
                } else if (pattern.charAt(j - 1) == '?' || str.charAt(i - 1) == pattern.charAt(j - 1)) {
                    lookup[i][j] = lookup[i - 1][j - 1];
                } else {
                    lookup[i][j] = false;
                }
            }
        }
        return lookup[n][m];
    }

    public static void main(String[] args) {
        String str="baaababa";
        String pat="b*ba";
        if(strMatch(str, pat, str.length(), pat.length())){
            System.out.println("Si");
        }else{
            System.out.println("No");
        }
    }
}
