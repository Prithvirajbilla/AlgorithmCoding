import json

#reading the input
inp = ""
while True:
	try:
		inp+=raw_input().strip()
	except EOFError:
		#do nothing
		break
json_data = json.loads(inp)

# print json_data
def cal_exp(k):
	if isinstance(k,unicode):
		return int(k)
	elif isinstance(k,str):
		return int(k)
	elif isinstance(k,dict):
		if "expr" in [l.lower() for l in k.keys()]:
			return cal_exp(k[k.keys()[0]])
		elif "sum" in [l.lower() for l in k.keys()]:
			ans = 0
			for i in k[k.keys()[0]]["elem"]:
				ans = ans+ cal_exp(i);
			return ans
		elif "sub" in [l.lower() for l in k.keys()]:
			ans = cal_exp(k[k.keys()[0]]["elem"][0])
			for i in k[k.keys()[0]]["elem"][1:]:
				ans -= cal_exp(i)
			return ans
		elif "prod" in [l.lower() for l in k.keys()]:
			ans = 1
			for i in k[k.keys()[0]]["elem"]:
				ans*=cal_exp(i);
			return ans
		elif "div" in [l.lower() for l in k.keys()]:
			ans = cal_exp(k[k.keys()[0]]["elem"][0])*1./cal_exp(k[k.keys()[0]]["elem"][1]);
			return ans

print cal_exp(json_data["expr"])
