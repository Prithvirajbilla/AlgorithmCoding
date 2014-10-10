T = input()
for i in xrange(T):
	s = raw_input().strip()
	l = list(s)
	l.sort(reverse = True)
	new_s = "".join(l)
	if new_s == s:
		print "no answer"
	else:
		l = list(s[1:])
		l.sort(reverse = True)
		new_s1 ="".join(l)
		new_s1 = s[0]+new_s1
		print new_s1
		if new_s1 != new_s:
			print new_s1
		else:
			print new_s