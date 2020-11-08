#!/usr/bin/env python3
str1 = b"MindBlown%"
str2 = b"\x03\x05\x02\x04\x01\x07\x03\x01\x00\x00"

for i in zip(str1,str2):
	print(chr(i[0] + i[1]),end='')