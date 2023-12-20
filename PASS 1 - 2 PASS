#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char label[10],opcode[10],operand[10],code[10];
    int locctr,start,length;
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("input.txt","r");
    fp2=fopen("symtab.txt","w");
    fp3=fopen("out.txt","w");
    fp4=fopen("opcode.txt","r");
    fscanf(fp1,"%s%s%s",label,opcode,operand);
    if (strcmp(opcode,"START")==0)
    {
        start=atoi(operand);
        locctr=start;
        fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s%s%s",label,opcode,operand);
    }
    else    
    locctr=0;
    while (strcmp(opcode,"END")!=0)
    {
        fprintf(fp3,"%d\t",locctr);
        if (strcmp(label,"**")!=0)
        {
            fprintf(fp2,"%d\t%s\n",locctr,label);
        }
        rewind(fp4);
        fscanf(fp4,"%s",code);
        while (strcmp(code,"END")!=0)
        {
            if (strcmp(opcode,code)==0)
            {
                locctr+=3;
                break;
            }
            fscanf(fp4,"%s",code);
        }
        if (strcmp(opcode,"WORD")==0)
        locctr+=3;
        else if (strcmp(opcode,"RESW")==0)
        locctr+=(3*(atoi(operand)));
        else if (strcmp(opcode,"RESB")==0)
        locctr+=(atoi(operand));
        else if (strcmp(opcode,"BYTE")==0)
        ++locctr;
        fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s%s%s",label,opcode,operand);
    }
    fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    length=locctr-start;
    printf("The length of the program is %d\n",length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}


INPUT.TXT
---------
** START 2000
** LDA FIVE
** STA ALPHA
** LDCH CHARZ
** STCH C1
ALPHA RESW 1
FIVE WORD 5
CHARZ BYTE C'Z'
C1 RESB 1
** END 2000

OPCODE.TXT
---------
START **
LDA 03
STA 0F
LDCH 53
STCH 57
END **



OUTPUT
--------

SYMTAB.TXT
----------
2012	ALPHA
2015	FIVE
2018	CHARZ
2019	C1


OUT.TXT
--------
	**	START	2000
2000	**	LDA	FIVE
2003	**	STA	ALPHA
2006	**	LDCH	CHARZ
2009	**	STCH	C1
2012	ALPHA	RESW	1
2015	FIVE	WORD	5
2018	CHARZ	BYTE	C'Z'
2019	C1	RESB	1
2020	**	END	2000
