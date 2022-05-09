K , L = map(int, input().split())
flag=0
for i in range(2,L):
	if K%i==0:
		print("BAD "+ str(i))
		flag=1
		break;

if flag==0:
	print("GOOD")