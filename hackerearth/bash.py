# count = 0;
# while count < 9:
# 	k = raw_input().strip().split()
# 	count += len(k)
# 	l +=k;
# [a,b,c,d,e,f,g,h,i] = l;
# print a,b,c,f,i,h,g,d,e
# from itertools import permutations
# perms = [''.join(p) for p in permutations(['a','b','c','d','e','f','g','h','i'])]
# print perms.index('abcfihgde')
l = []
count = 0;
while True:
	try:
		k = raw_input().strip().split()
		count += len(k)
		l +=k;
	except EOFError:
		#do nothing
		break

def getPerm(seq, index):
	seqc= list(seq[:])
	seqn= [seqc.pop()]
	divider= 2 # divider is meant to be len(seqn)+1, just a bit faster
	while seqc:
		index, new_index= index//divider, index%divider
		seqn.insert(new_index, seqc.pop())
		divider+= 1
	return seqn
ans=getPerm(l,581)
# print ans.index()
for i in ans:
	print i,
print 
