
undefined8 main(int iParm1,long lParm2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  undefined8 local_1e;
  undefined2 local_16;
  undefined local_14;
  undefined8 local_13;
  undefined2 local_b;
  undefined local_9;
  
  if (iParm1 == 2) {
    local_13 = 0x776f6c42646e694d;
    local_b = 0x256e;
    local_9 = 0;
    local_1e = 0x103070104020503;
    local_16 = 0;
    local_14 = 0;
    pcVar2 = *(char **)(lParm2 + 8);
    lVar5 = -1;
    pcVar6 = pcVar2;
    do {
      if (lVar5 == 0) break;
      lVar5 = lVar5 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != 0);
    if ((lVar5 == -0xc) && (iVar3 = check_pw(pcVar2,&local_13,&local_1e), iVar3 != 0)) {
      printf("Yes, %s is correct! The password is the flag: Format is apuboh{...}\n",pcVar2);
      return 0;
    }
    printf("No, %s is not correct.\n",pcVar2);
    uVar4 = 1;
  }
  else {
    puts("Need exactly one argument.");
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



undefined8 check_pw(long lParm1,long lParm2,long lParm3)

{
  long lVar1;
  
  lVar1 = 0;
  while( true ) {
    if (*(char *)(lParm1 + lVar1) != (char)(*(char *)(lParm3 + lVar1) + *(char *)(lParm2 + lVar1)))
    {
      return 0;
    }
    if (*(char *)(lParm2 + 1 + lVar1) == 0) break;
    lVar1 = lVar1 + 1;
    if (*(char *)(lParm1 + lVar1) == 0) {
      return 1;
    }
  }
  return 1;
}
