# Coded_VI (Reverse)

We're given a ELF file: [Coded_VI](./Coded_VI)

Test run it:
```
./Coded_VI 
Need exactly one argument.

./Coded_VI aaaaaaaaaaaaa
No, aaaaaaaaaaaaa is not correct. Have a sip of coffee
```

Open it in Ghidra to decompile it:

**main function code:**c
```c
int main(int argc, char const *argv[])
{
  char cVar1;
  char *input;
  char *str1 = "Tranqulat3d";
  char *str2 = "\x00\x00\x00\x00\x00 0 0P ";
  
  if (argc == 2) {

    input = argv[1];
    
    if ((strlen(input) == 12) && (check_pw(input,str1,str2) != 0)) {
      printf("Yes, %s is correct! The password is the flag: Format is apuboh{...}\n",input);
      return 0;
    }
    printf("No, %s is not correct. Have a sip of coffee\n",input);
  }
  else {
    puts("Need exactly one argument.");
  }
}
```
We can see is similar to the previous challenge [Codex_II](https://github.com/Hong5489/APUBOH2020/tree/main/codex_II), just some variable is different

The `check_pw` function is the same as previous challenge

Therefore, we can use the same script the solve it!

```py
#!/usr/bin/env python3
str1 = b"Tranqulat3d"
str2 = b"\x02\x03\x02\x03\x05\x02\x00\x00\x00\x00\x00"

for i in zip(str1,str2):
	print(chr(i[0] + i[1]),end='')
# Vucqvwlat3d
```
Verify with the program, and it was correct!
```
./Coded_VI Vucqvwlat3d
Yes, Vucqvwlat3d is correct! The password is the flag: Format is apuboh{...}
```

## Flag
```
apuboh{Vucqvwlat3d}
```