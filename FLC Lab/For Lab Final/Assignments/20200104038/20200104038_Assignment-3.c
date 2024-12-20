
#include <stdio.h>
#include <string.h>

char a[10000], b[10000], temp[10000], c[1000][100];
int inde[10000];
int cur = 0;

struct data
{
    char name[100];
    char idType[100];
    char dataType[100];
    char scope[100];
    char value[100];
} v[100];

void insert(int ind, char _name[], char _id[], char _dat[], char _scope[], char _value[])
{
    strcpy(v[ind].name, _name);
    strcpy(v[ind].idType, _id);
    strcpy(v[ind].dataType, _dat);
    strcpy(v[ind].scope, _scope);
    strcpy(v[ind].value, _value);
}

void display()
{
    int i = 0;
    printf("\nSl. No.\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n");
    for (i = 0; i < cur; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", i + 1, v[i].name, v[i].idType, v[i].dataType, v[i].scope, v[i].value);
    }
}

int search(char _name[], char _id[], char _scope[])
{
    int i = 0;
    for (i = 0; i < cur; i++)
    {
        if (strcmp(v[i].name, _name) == 0 && strcmp(v[i].idType, _id) == 0 && strcmp(v[i].scope, _scope) == 0)
        {
            return i;
        }
    }
    return -1;
}

char *Table_Value(char x[])
{
    if (strlen(x) == 0)
        return x;
    for (int i = 0; i < strlen(x); i++)
    {
        if (!(x[i] >= '0' && x[i] <= '9') && x[i] != '.')
            return "";
    }
    return x;
}

void update(int cur, char val[])
{
    strcpy(v[cur].value, val);
}
void deleteEntry(int index)
{
    if (index < 0 || index >= cur)
    {
        printf("Invalid index for deletion.\n");
        return;
    }

    // Move elements after the index to fill the gap
    for (int i = index; i < cur - 1; i++)
    {
        strcpy(v[i].name, v[i + 1].name);
        strcpy(v[i].idType, v[i + 1].idType);
        strcpy(v[i].dataType, v[i + 1].dataType);
        strcpy(v[i].scope, v[i + 1].scope);
        strcpy(v[i].value, v[i + 1].value);
    }

    cur--; // Decrement the count of elements
    printf("Entry at index %d deleted successfully.\n", index + 1);
}
int main()
{
    int i, n, t, k, j, x = 0, y = 0, m;
    FILE *fp = fopen("input1.txt", "r");
    i = 0;
    while (fscanf(fp, "%c", &a[i]) != EOF)
    {
        i++;
    }
    a[i] = '\0';
    fclose(fp);
    printf("Input: \n");
    puts(a);
    k = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '[')
        {
            b[k++] = a[i++];
            j = 0;
            while (a[i] != ' ')
            {
                temp[j++] = a[i];
                i++;
            }
            temp[j] = '\0';
            if (strcmp(temp, "id") == 0)
            {
                b[k++] = 'i';
                b[k++] = 'd';
                b[k++] = ' ';
            }
            i++;
            while (a[i] != ']')
            {
                b[k++] = a[i];
                i++;
            }
            b[k++] = a[i];
        }
    }
    b[k] = '\0';
    printf("\nStep 1: \n");
    puts(b);
    fp = fopen("Output-1.txt", "w");
    fputs(b, fp);
    fclose(fp);
    k = 0;
    for (i = 0; i < strlen(b); i++)
    {
        if (b[i] == '[')
        {
            j = 0;
            i++;
            while (b[i] != ']' && b[i] != ' ')
            {
                c[k][j++] = b[i++];
            }
            c[k][j] = '\0';
            k++;
            if (b[i] == ' ')
            {
                j = 0;
                i++;
                while (b[i] != ']')
                {
                    c[k][j++] = b[i++];
                }
                c[k][j] = '\0';
                k++;
            }
        }
    }
    printf("\nStep 2: \n");
    int it = 0;
    char scope[100] = "global";
    for (i = 0; i < k; i++)
    {
        if (strcmp(c[i], "id") == 0)
        {
            if (strcmp(c[i + 2], "(") == 0)
            {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0)
                {
                    inde[it++] = cur;
                    insert(cur++, c[i + 1], "func", c[i - 1], scope, "");
                    strcpy(scope, c[i + 1]);
                    i += 2;
                }
                else
                {
                    int pq = search(c[i + 1], "func", "global");
                    if (pq != -1)
                        inde[it++] = pq;
                    else
                        printf("\nID %s is not declared in global scope\n", c[i + 1]);
                    i += 2;
                }
            }
            else if (strcmp(c[i + 2], "=") == 0)
            {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0)
                {
                    if (search(c[i + 1], "var", scope) == -1)
                    {
                        inde[it++] = cur;
                        insert(cur++, c[i + 1], "var", c[i - 1], scope, Table_Value(c[i + 3]));
                    }
                    else
                    {
                        printf("\nID %s already declared in %s scope\n", c[i + 1], scope);
                    }
                }
                else
                {
                    int pq = search(c[i + 1], "var", scope);
                    if (pq == -1)
                    {
                        printf("\nID %s is not declared in %s scope\n", c[i + 1], scope);
                    }
                    else
                    {
                        update(pq, Table_Value(c[i + 3]));
                        inde[it++] = pq;
                    }
                }
                i += 2;
            }
            else if (strcmp(c[i + 2], ";") == 0 || strcmp(c[i + 2], ",") == 0 || strcmp(c[i + 2], ")") == 0)
            {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0)
                {
                    if (search(c[i + 1], "var", scope) == -1)
                    {
                        inde[it++] = cur;
                        insert(cur++, c[i + 1], "var", c[i - 1], scope, "");
                    }
                    else
                        printf("\nID %s already declared in %s scope\n", c[i + 1], scope);
                    i += 2;
                }
                else
                {
                    if (search(c[i + 1], "var", scope) == -1)
                    {
                        printf("\nID %s is not declared in %s scope\n", c[i + 1], scope);
                    }
                    else
                        inde[it++] = search(c[i + 1], "var", scope);
                    i += 2;
                }
            }
        }
        else if (strcmp(c[i], "}") == 0)
        {
            strcpy(scope, "global");
        }
    }
    display();
    printf("\nStep 3:\nALL THE 5 FUNCTIONS HAVE BEEN IMPLEMENTED\n");
    printf("\nStep 4:\n");

    fp = fopen("Output-2.txt", "w");
    it = 0;
    for (i = 0; i < strlen(b); i++)
    {
        if (b[i] == '[')
        {
            printf("%c", b[i]);
            fputc(b[i], fp);
            i++;
            while (b[i] != ']' && b[i] != ' ')
            {
                printf("%c", b[i]);
                fputc(b[i], fp);
                i++;
            }
            if (b[i] == ' ')
            {
                printf("%c", b[i]);
                fputc(b[i], fp);
                j = 0;
                i++;
                while (b[i] != ']')
                {
                    i++;
                }
                fputc(inde[it] + 1 + 48, fp);
                printf("%d", inde[it++] + 1);
            }
            printf("%c", b[i]);
            fputc(b[i], fp);
        }
        else
        {
            printf("%c", b[i]);
        }
    }
    fclose(fp);


    //For deletion
    printf("\n\nAfter deletion:\n");
    deleteEntry(0);
    display();
    return 0;
}
