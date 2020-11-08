text = open("ffffff",'r').read()
# for i,t in enumerate(text):
# 	if t != "\xff":
# 		print i,repr(t)
print (5243252-5243077)%8
text = text[5243077-7:5243252].replace("\xff",'0').replace("\xfe",'1')
print hex(int(text,2))[2:-1].decode("hex")