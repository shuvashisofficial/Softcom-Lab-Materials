#include<stdio.h>
#include<string.h>

int tablei = 0;
struct sTable
{
    char name[20][20];
    char idType[20][20];
    char dataType[20][20];
    char scope[20][20];
    char value[20][20];
} sTable;

int main()
{
    FILE *ptr, *ptr2;
    int inputi=0;
    int i, j;
    char input[1500], c;
    char scp[20] = "global";

    ptr = fopen("input.txt","r");
    printf("Input file:\n");
    while((c=getc(ptr))!=EOF)
    {
        printf("%c",c);
        input[inputi]=c;
        inputi++;
    }
    fclose(ptr);

    ptr2 = fopen("output.txt","w");
    printf("\nStep 1:\n");

    for( i = 0; i<inputi; i++)
    {
        if(input[i] == '[' && input[i+1]== 'i' && input[i+2]=='d' && input[i+3]==' ')
        {
            i+=4;
            j = 0;
            char id[20];
            while(input[i] != ']')
            {
                id[j] = input[i];
                i++;
                j++;
            }
            id[j] = '\0';
            printf("[id %s",id);
            fprintf(ptr2,"[id %s",id);
        }
        if(input[i]=='[')
        {
            printf("[");
            fputc('[',ptr2);
            while(input[i]!=' ')
                i++;
            i++;
        }

        printf("%c",input[i]);
        fputc(input[i],ptr2);
    }
    fclose(ptr2);

    for( i = 0;i<inputi;i++)
    {
        if(input[i] == 'k' && input[i+1] == 'w' && input[i+3]!='r')
        {
            char dT[20],n[20],v[20];
            j=0;
            i+=3;
            while(input[i]!=']')
            {
                dT[j] = input[i];
                j++;
                i++;
            }
            dT[j] = '\0';
            i+=3;
            if(input[i]=='i' && input[i+1] == 'd' && input[i+2] == ' ')
            {
                i+=3;
                j=0;
                while(input[i] !=']')
                {
                    n[j] = input[i];
                    i++;
                    j++;
                }
                n[j] = '\0';

                i+=3;

                if(input[i] == 's' || input[i] == 'o')
                {
                    if(input[i] == 's')
                        strcpy(sTable.name[tablei], n);
                    else
                    {
                        i+=10;
                        j = 0;
                        while(input[i] != ']')
                        {
                            v[j] = input[i];
                            j++;
                            i++;
                        }
                        v[j] = '\0';
                        strcpy(sTable.value[tablei], v);
                    }
                    strcpy(sTable.idType[tablei], "var");
                    strcpy(sTable.dataType[tablei], dT);
                    strcpy(sTable.scope[tablei], scp);
                    tablei++;
                }
                else
                {
                    i+=4;
                    if(input[i]==')')
                    {
                        strcpy(sTable.name[tablei], n);
                        strcpy(sTable.idType[tablei], "var");
                        strcpy(sTable.dataType[tablei], dT);
                        strcpy(sTable.scope[tablei], scp);
                        tablei++;
                    }
                    else
                    {
                        strcpy(sTable.name[tablei], n);
                        strcpy(sTable.idType[tablei], "func");
                        strcpy(sTable.dataType[tablei], dT);
                        strcpy(sTable.scope[tablei], "global");
                        tablei++;
                        strcpy(scp, n);
                    }
                }
            }
        }
        else if(input[i]=='[' && input[i+1]=='i' && input[i+2] == 'd' && input[i+3]== ' ')
        {
            char n[20],v[20];
            i+=4;
            j = 0;
            while(input[i] != ']')
            {
                n[j] = input[i];
                j++;
                i++;
            }
            n[j]='\0';
            i+=3;
            if(input[i]=='o' && input[i+7] == 'n')
            {
                i+=10;
                j=0;
                while(input[i] != ']')
                {
                    v[j] = input[i];
                    j++;
                    i++;
                }
                v[j] = '\0';
                for(j = 0; j < tablei; j++)
                {
                    if(strcmp(sTable.name[j], n) == 0 && strcmp(sTable.scope[j], scp) == 0)
                    {
                        strcpy(sTable.value[j], v);
                        break;
                    }
                }
            }
        }
        else if(input[i]=='}')
        {
            strcpy(scp,"global");
        }
    }
    int lookUp(char n[], char scp[])
    {
        int i;
        for(i = 0; i<tablei; i++)
            if(strcmp(sTable.name[i],n)==0)
            {
                if(strcmp(sTable.idType[i],"func")==0)
                {
                    return (i+1);
                }
                else if(strcmp(sTable.scope[i],scp)==0)
                {
                    return (i+1);
                }
            }
    }
    printf("\n\nStep 2:\n");
    printf("\nSl.No.\tName\tId Type\tData Type\tScope\tValue\n-------------------------------------------------------\n");
    for( i = 0; i<tablei ; i++)
    {
        printf("%d\t|%s\t|%s\t|%s\t\t|%s\t|%s\n",(i+1),sTable.name[i],sTable.idType[i],sTable.dataType[i],sTable.scope[i],sTable.value[i]);
    }

    strcpy(scp,"global");
    printf("\nStep 4: Modified token stream for Syntax Analysis: \n");
    ptr2 = fopen("output2.txt","w");

    for( i = 0;i<inputi;i++)
    {
        if(input[i] == '[' && input[i+1]== 'i' && input[i+2]=='d' && input[i+3]==' ')
        {
            i+=4;
            j = 0;
            char id[20];
            while(input[i] != ']')
            {
                id[j] = input[i];
                i++;
                j++;
            }
            id[j] = '\0';
            printf("[id %d",lookUp(id,scp));
            fprintf(ptr2,"[id %d",lookUp(id,scp));
            if(input[i+3]=='p' && input[i+7]=='(' && strcmp(scp,"global") == 0)
                strcpy(scp,id);
        }
        if(input[i]=='[')
        {
            printf("[");
            fputc('[',ptr2);
            while(input[i]!=' ')
                i++;
            i++;
        }
        if(input[i] == '}')
            strcpy(scp,"global");
        printf("%c",input[i]);
        fputc(input[i],ptr2);
    }

    fclose(ptr2);
    return 0;
}
