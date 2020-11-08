# Codex_II (Reverse)

We're given a ELF file: [Codex_II](./Codex_II)

Test run it:
```
./Codex_II 
Need exactly one argument.

./Codex_II aaaaaaaaa
No, aaaaaaaaa is not correct.

```
Looks like it require a password, try `strings` command found some string:
```
...
Need exactly one argument.
No, %s is not correct.
Yes, %s is correct! The password is the flag: Format is apuboh{...}
...
```
Therefore the password is also the flag for this challenge!

Lets decompile it with ghidra

*Note: I modify the code the make it more readable, orginal source: [source.c](source.c)*

**main function:**
```c
int main(int argc, char const *argv[])
{
  char cVar1;
  char *input;
  char *str1 = "MindBlown%";
  char *str2 = "\x03\x05\x02\x04\x01\x07\x03\x01\x00\x00";
  
  if (argc == 2) {

    input = argv[1];
    
    if ((strlen(input) == 11) && (check_pw(input,str1,str2) != 0)) {
      printf("Yes, %s is correct! The password is the flag: Format is apuboh{...}\n",input);
      return 0;
    }
    printf("No, %s is not correct.\n",input);
  }
  else {
    puts("Need exactly one argument.");
  }
}
```
From the code above, we know that the argument we pass in must be **11 characters**, and passed in `check_pw` function

**check_pw function:**
```c
int check_pw(char* input,char* str1,char* str2)

{
  int i = 0;
  while( true ) {
    if (input[i] != (str2[i] + str1[i]))
    {
      return 0;
    }
  }
  return 1;
}
```
The check_pw function add the two strings together and compare it with the argument (input)

Therefore, we add the two strings together to get the password!

I used Python to calculate this for me:
```py
#!/usr/bin/env python3
str1 = b"MindBlown%"
str2 = b"\x03\x05\x02\x04\x01\x07\x03\x01\x00\x00"

for i in zip(str1,str2):
	print(chr(i[0] + i[1]),end='')
# PnphCsrxn%
```
Alternatively, solve in C language:
```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char *str1 = "MindBlown%";
  	char *str2 = "\x03\x05\x02\x04\x01\x07\x03\x01\x00\x00";
  	for (int i = 0; i < 11; ++i)
  	{
  		printf("%c",str1[i]+str2[i]);
  	}
	return 0;
}
// PnphCsrxn%
```
Verify the password with the program, and its correct!
```
./Codex_II PnphCsrxn%
Yes, PnphCsrxn% is correct! The password is the flag: Format is apuboh{...}
```

## Flag
```
apuboh{PnphCsrxn%}
```