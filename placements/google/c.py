t = int(raw_input().strip())
for i in xrange(t):
	n = int(raw_input().strip())
	l = {}
	dl = {}
	for k in xrange(n):
		src = raw_input().strip()
		dest = raw_input().strip()
		l[src] = dest
		if src in dl:
			dl[src]+=1
		else:
			dl[src] = 1
		if dest in dl:
			dl[dest]+=1
		else:
			dl[dest] = 1

	#find the src with one
	csr = "" 
	for k in dl:
		if dl[k] == 1 and k in l:
			csr = k
			break;
	ans = ""
	cto = 0;
	while cto < n:
		ans += csr+"-"+l[csr]+" "
		csr = l[csr]
		cto+=1

	print "Case #%d:"%(i+1),ans
