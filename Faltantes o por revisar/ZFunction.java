//Dado un string s retorna un arreglo z donde z[i] es igual 
//al mayor numero de caracteres desde s[i] que coinciden 
//con los caracteres desde s[0]

public class ZFunction {

    static int[] zfunction(String ss) {
        String s = ss;
        int n = s.length();
        int[] z = new int[n];
        for (int i = 1, x = 0, y = 0; i < n; i++) {
            z[i] = Math.max(0, Math.min(z[i - x], y - i + 1));
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) {
                x = i;
                y = i + z[i];
                z[i]++;
            }
        }
        return z;
    }
    
    public static void main(String[] args) {
        String s = "holamundohhhhhh";
        int []res=zfunction(s);
        for (int i : res) {
            System.out.print(i+" ");
        }
    }
}
