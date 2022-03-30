a,b=map(int,input().split())
if(b>0):
  print(a//b)
  print(a%b)
else:
  c=-b
  print(-(a//c))
  print(a%c)