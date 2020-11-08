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