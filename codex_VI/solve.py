#!/usr/bin/env python3
str1 = b"Tranqulat3d"
str2 = b"\x02\x03\x02\x03\x05\x02\x00\x00\x00\x00\x00"

for i in zip(str1,str2):
	print(chr(i[0] + i[1]),end='')