#include<stdio.h> 
#define MAXLEN 100
int main()
{
	char index[MAXLEN],ch;
	int next=0,i,ENG=0,VOI=0,EXC=0,ENT=0,OTH=0;
	printf("请输入一段字符：\n");
	while((ch=getchar())!=EOF)
		index[next++]=ch;
	for(i=0;i<=next-1;i++) 
	{
	    if((index[i]>='a'&&index[i]<='z')||(index[i]>='A'&&index[i]<='Z'))
	        ENG++;
	    else if(index[i]==' ')
	            VOI++;
	        else if(index[i]=='\t')
	                EXC++;
	            else if(index[i]=='\n')
	                    ENT++;
	                else OTH++;
    }
	printf("英文字符有%d个\n空格有%d个\n制表符有%d个\n换行符有%d个\n其他字符有%d个\n",ENG,VOI,EXC,ENT,OTH);
}
