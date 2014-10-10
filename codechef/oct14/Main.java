import java.io.*;


public class Main
{
	public static int levenshtein(String s, String t, int threshold) {
    int slen = s.length();
    int tlen = t.length();

    // swap so the smaller string is t; this reduces the memory usage
    // of our buffers
    if(tlen > slen) {
        String stmp = s;
        s = t;
        t = stmp;
        int itmp = slen;
        slen = tlen;
        tlen = itmp;
    }

    // p is the previous and d is the current distance array; dtmp is used in swaps
    int[] p = new int[tlen + 1];
    int[] d = new int[tlen + 1];
    int[] dtmp;

    // the values necessary for our threshold are written; the ones after
    // must be filled with large integers since the tailing member of the threshold 
    // window in the bottom array will run min across them
    int n = 0;
    for(; n < Math.min(p.length, threshold + 1); ++n)
        p[n] = n;
    Arrays.fill(p, n, p.length, Integer.MAX_VALUE);
    Arrays.fill(d, Integer.MAX_VALUE);

    // this is the core of the Levenshtein edit distance algorithm
    // instead of actually building the matrix, two arrays are swapped back and forth
    // the threshold limits the amount of entries that need to be computed if we're 
    // looking for a match within a set distance
    for(int row = 1; row < s.length()+1; ++row) {
        char schar = s.charAt(row-1);
        d[0] = row;

        // set up our threshold window
        int min = Math.max(1, row - threshold);
        int max = Math.min(d.length, row + threshold + 1);

        // since we're reusing arrays, we need to be sure to wipe the value left of the
        // starting index; we don't have to worry about the value above the ending index
        // as the arrays were initially filled with large integers and we progress to the right
        if(min > 1)
            d[min-1] = Integer.MAX_VALUE;

        for(int col = min; col < max; ++col) {
            if(schar == t.charAt(col-1))
                d[col] = p[col-1];
            else 
                // min of: diagonal, left, up
                d[col] = Math.min(p[col-1], Math.min(d[col-1], p[col])) + 1;
        }
        // swap our arrays
        dtmp = p;
        p = d;
        d = dtmp;
    }

        if(p[tlen] == Integer.MAX_VALUE)
            return -1;
    return p[tlen];
}
	public static void main (String[] args) throws java.lang.Exception
	{
		
	}
}