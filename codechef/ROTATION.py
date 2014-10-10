l = [int(k) for k in raw_input().strip().split()]
n = l[0]; m = l[1]
array = raw_input().strip().split()
i = 0
pointer = 0
while i < m:
	k = raw_input().strip().split()
	if k[0] == "A":
		pointer -= int(k[1]);
		pointer %= n
	elif k[0] == "C":
		pointer += int(k[1]);
		pointer %= n
	elif k[0] == "R":
		r = pointer+int(k[1])-1
		r %= n
		print array[r]
	i+=1