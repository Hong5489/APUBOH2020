# ffffff (Steganography)
We are given a file: [ffffff](ffffff)

Just a file contains alot of FF bytes:
```
xxd ffffff | head
00000000: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000010: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000020: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000030: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000040: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000050: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000060: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000070: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000080: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000090: ffff ffff ffff ffff ffff ffff ffff ffff  ................
```
I guess it should contain other bytes other than `FF` so I wrote a python script to find it:
```py
text = open("ffffff",'r').read()
for i,t in enumerate(text):
	if t != "\xff":
		print i,repr(t)
```
Result:
```
5243077 '\xfe'
5243078 '\xfe'
5243083 '\xfe'
5243085 '\xfe'
5243086 '\xfe'
5243087 '\xfe'
5243093 '\xfe'
5243094 '\xfe'
5243095 '\xfe'
5243097 '\xfe'
5243099 '\xfe'
5243101 '\xfe'
5243102 '\xfe'
5243106 '\xfe'
5243109 '\xfe'
5243110 '\xfe'
5243112 '\xfe'
5243113 '\xfe'
5243114 '\xfe'
5243115 '\xfe'
5243117 '\xfe'
5243118 '\xfe'
5243120 '\xfe'
5243125 '\xfe'
5243126 '\xfe'
5243127 '\xfe'
5243128 '\xfe'
5243130 '\xfe'
5243131 '\xfe'
5243133 '\xfe'
5243134 '\xfe'
5243138 '\xfe'
5243141 '\xfe'
5243142 '\xfe'
5243146 '\xfe'
5243149 '\xfe'
5243150 '\xfe'
5243154 '\xfe'
5243157 '\xfe'
5243158 '\xfe'
5243162 '\xfe'
5243165 '\xfe'
5243166 '\xfe'
5243170 '\xfe'
5243173 '\xfe'
5243174 '\xfe'
5243176 '\xfe'
5243179 '\xfe'
5243181 '\xfe'
5243182 '\xfe'
5243184 '\xfe'
5243185 '\xfe'
5243186 '\xfe'
5243189 '\xfe'
5243190 '\xfe'
5243195 '\xfe'
5243197 '\xfe'
5243198 '\xfe'
5243199 '\xfe'
5243202 '\xfe'
5243205 '\xfe'
5243206 '\xfe'
5243209 '\xfe'
5243211 '\xfe'
5243213 '\xfe'
5243214 '\xfe'
5243217 '\xfe'
5243219 '\xfe'
5243221 '\xfe'
5243222 '\xfe'
5243225 '\xfe'
5243227 '\xfe'
5243229 '\xfe'
5243230 '\xfe'
5243233 '\xfe'
5243235 '\xfe'
5243237 '\xfe'
5243238 '\xfe'
5243241 '\xfe'
5243243 '\xfe'
5243245 '\xfe'
5243246 '\xfe'
5243247 '\xfe'
5243248 '\xfe'
5243249 '\xfe'
5243251 '\xfe'
```
Yes! Looks like we have something hidden starting on bytes no.5243077 to no.5243182

Simply guessing, only `FF` and `FE` in the file, so like whitespace steganography

One represent 0 and another represent 1

First need to know the length of the string is in multiple of 8 (Because 1 character 8bits)

```py
print (5243252-5243077)%8
# 7
```
So the hidden flag should be plus minus 7 offset of the text

First need guess which is 0 and 1, I guess `FF` is 1 and `FE` is 0:
```py
text = text[5243077+7:5243252].replace("\xff",'1').replace("\xfe",'0')
print hex(int(text,2))
# 0x8f8a9d9097849d9d9d9d9d96919e8d9a9a9a9a9a82L
```
The result not like ASCII hex value, so should be the other way around!
```py
text = text[5243077+7:5243252].replace("\xff",'0').replace("\xfe",'1')
print hex(int(text,2))
# 0x7075626f687b6262626262696e617265656565657dL
```
Looks like ASCII!! Decode it!
```
puboh{bbbbbinareeeee}
```
Missing `a` infront (Because the flag format start with `apuboh`), so the offset -7 should be correct: 
```py
text = text[5243077-7:5243252].replace("\xff",'0').replace("\xfe",'1')
print hex(int(text,2))[2:-1].decode("hex")
# apuboh{bbbbbinareeeee}
```

## Flag
```
apuboh{bbbbbinareeeee}
```