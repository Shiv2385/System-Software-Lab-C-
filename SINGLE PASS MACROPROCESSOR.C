#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 50
#define MAX_MACROS 20

int main() {
    char input[MAX_LINES][MAX_LENGTH];
    char output[MAX_LINES * MAX_LENGTH]; 
    char namtab[MAX_MACROS][MAX_LENGTH];
    int n = 0;

    FILE *fp1 = fopen("macroin.txt", "r");
    FILE *fp2 = fopen("macroout.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.");
        return 1;
    }

    while (fgets(input[n], MAX_LENGTH, fp1) != NULL) {
        input[n][strlen(input[n]) - 1] = '\0'; 
        n++;
    }

    int macroStart = -1;
    int macroEnd = -1;
    int macroCount = 0;

    for (int i = 0; i < n; i++) {
        char ilab[MAX_LENGTH], iopd[MAX_LENGTH], oper[MAX_LENGTH];
        sscanf(input[i], "%s %s %s", ilab, iopd, oper);

        if (strcmp(iopd, "MACRO") == 0) {
            macroStart = i;
        } else if (strcmp(iopd, "MEND") == 0) {
            macroEnd = i;
            i = macroStart - 1;

            while (++i < macroEnd) {
                char innerIlab[MAX_LENGTH], innerIopd[MAX_LENGTH], innerOper[MAX_LENGTH];
                sscanf(input[i], "%s %s %s", innerIlab, innerIopd, innerOper);

                if (strcmp(innerIopd, "**") == 0) {
                    strcat(output, innerOper);
                    strcat(output, "\n");
                }
            }

            i = macroEnd;
        } else {
            if (strcmp(iopd, "**") != 0) {
                int flag = 0;

                for (int j = 0; j < macroCount; j++) {
                    if (strcmp(iopd, namtab[j]) == 0) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    strcat(output, input[i]);
                    strcat(output, "\n");
                }
            } else {
                strcpy(namtab[macroCount], oper);
                macroCount++;
            }
        }
    }

    fprintf(fp2, "%s", output);

    fclose(fp1);
    fclose(fp2);

    return 0;
}



MACROIN.TXT
-----------
M1 MACRO **
** LDA N1
** ADD N2
** STA N3
** MEND **
M2 MACRO **
** LDA N1
** SUB N2
** STA N4
** MEND **
M3 MACRO **
** LDA N1
** MUL N1
** STA N3
** MEND **
** START 1000
** M3 **
** M2 **
** M1 **
** END **


OUTPUT
-------
MACROOUT.TXT
-------------
** START 1000
** LDA N1
** MUL N1
** STA N3
** LDA N1
** SUB N2
** STA N4
** LDA N1
** ADD N2
** STA N3
** END **
