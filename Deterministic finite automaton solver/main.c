//Luis Tessaro / Felipe Perozo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global vars
char alphabet[10];
int states;
int numberOfFinalStates;
char finalStates[19];
int numberOfTransitions;
char transtions[100][3];
int numberOfWords;
char word[100][100];

//methods
int readFile();
int find(char x, char y);
int solve();
void printSolved();

int main()
{
    readFile();
    printSolved();
    return 0;
}

int find(char x, char y)
{//linear search improve maybe?
    int i;
    for(i = 0; i < numberOfTransitions; i++)
        if(x == transtions[i][0] && y == transtions[i][1])
            return transtions[i][2];
    return -1;
}

int solve(char word[100])
{
    int q = strlen(word);
    int i;
    //'0' is inicial state
    char auxState = '0';

    for(i = 0; i < q; i++)
        auxState = find(auxState,word[i]);

    for(i = 0;i < numberOfFinalStates;i++)
        if( auxState == finalStates[i])
            return 0;

    return 1;
}

void printSolved()
{
    int i;
    for(i = 0; i < numberOfWords;i++)
        if(solve(word[i])== 0)
            printf("%s OK\n",word[i]);
        else
            printf("%s NOT OK\n",word[i]);
}

int readFile()
{
    FILE * pFile;
    pFile = fopen ("input.txt","r");
    if (!pFile)
    {
        printf("file not found\n");
        return -1;
    }
    else
    {
        fscanf(pFile,"%s",alphabet);
        fscanf(pFile,"%d",&states);
        fscanf(pFile,"%d",&numberOfFinalStates);
        int i,j;
        for(i = 0;i < numberOfFinalStates;i++)
            fscanf(pFile," %c",&finalStates[i]);

        fscanf(pFile,"%d",&numberOfTransitions);

        for(i = 0; i < numberOfTransitions; i++)
            for(j = 0; j < 3; j++)
                fscanf(pFile, " %c", &transtions[i][j]);

        fscanf(pFile,"%d",&numberOfWords);
        for(i = 0;i < numberOfWords;i++)
            fscanf(pFile,"%s",word[i]);
    }
    fclose(pFile);
    return 0;
}
