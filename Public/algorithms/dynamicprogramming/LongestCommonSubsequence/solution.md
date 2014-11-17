### Longest Common Subsequence 

Let X = {x1, x2, x3, x4, .. xm } and Y = { y1,y2,y3 ... yn} be sequences and Let Z = {z1,z2 ... zk} be the LCS of the X and Y.

* if xm = yn, then zk = xm = yn and Z(k-1) is an LCS of X(m-1) and Y(n-1).
* if xm != yn, then zk != xm implies that Z is an LCS of X(m-1) and Y .
* if xm ! = yn, then zk != yn implies that Z is an LCS of X and Y(n-1) .


LCS[i,j] be the length of the sequence Xi and Yj, then the recurrence equations can be given by


<pre>
<code>
LCS[i,j] = 0 if i = 0 , j = 0
	 = LCS[i-1,j-1]+1 if(i,j > 0) and xi = yj
         = longest(LCS[i,j-1],LCS[i-1,j]) if(i,j > 0) and  xi != yj
</code>
</pre>
