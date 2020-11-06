#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int charClass;
#define MAX_LEN 100
char lexeme[MAX_LEN];
char nextChar;
char next2Char;
int i=1;
int lexLen;
int token;
int nextToken;
FILE *inFile;

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 999

enum {ABSTRACT=258,CASE,CATCH,CLASS,DEF,DO,ELSE,EXTENDS,FALSE1,FINAL,FINALLY,FOR,FORSOME,IF,IMPLICIT,IMPORT,LAZY,MACRO,MATCH,NEW,NULL1,OBJECT,OVERRIDE,PACKAGE,PRIVATE,PROTECTED,RETURN,SEALED,SUPER,THIS,THROW,TRAIT,TRY,TRUE1,TYPE,VAL,VAR,WHILE,WITH,YIELD,ERROR,INT,FLOAT,ID,NOTE1,NOTE2,STRING,EQU,AEQU,LEQU,GEQU,MEQU,KEQU,NEQU};
char *keywords[]={"abstract","case","catch","class","def","do","else","extends","false","final","finally","for","forsome","if","implicit","import","lazy","macro","match","new","null","object","override","package","private","protected","return","sealed","super","this","throw","trait","try","true","type","val","var","while","with","yield","error","int","id",0};
void addChar()
{
   if(lexLen<=MAX_LEN-2)
    { 
      lexeme[lexLen++]=nextChar;
      lexeme[lexLen]=0;
     }
   else
     printf("ERROR:lexeme is too long.\n");
}

void getChar()
{
   static int firstRun=1;
   if(firstRun)
    {
      nextChar=getc(inFile);
      next2Char=getc(inFile);
      firstRun=0;
    }
    else
    {
      nextChar=next2Char;
      next2Char=getc(inFile);
    }
   
    if(nextChar==EOF)
    {
       charClass=EOF;
    }
    else
    {
       if(isalpha(nextChar))
          charClass=LETTER;
       else if(isdigit(nextChar))
          charClass=DIGIT;
       else
          charClass=UNKNOWN;
    }
}

void getNonBlank()
{
    while(isspace(nextChar))
      getChar();
}

void checkNote(){
     addChar();
     getChar();
     while(nextChar!='*')
     {
          addChar();
          getChar();
     }
     addChar();
     getChar();
     if(nextChar!='/')
     {
          checkNote();
     }
}

void checkNote2(){
     addChar();
     getChar();
     while(nextChar!='\n'){
          addChar();
          getChar();
     }
}

void checkstring2()
{
	addChar();
	getChar();
	if(nextChar='(')
	{
	      i++;
	}
	else if(nextChar=')')
	{
	      i--;
	}
	
}

void checkstring1()
{
     addChar();
     getChar();
     while(i!=0){
          checkstring2();
     }
}

int checkSymbol(char ch,char nextCh)
{
   switch(ch)
   {
    case';':
    case'+':
    case'-':
    case'_':
    case':':
    case'#':
    case'@':
    case'{':
    case'}':
    case'[':
    case']':
    case'&':
    case'.':
    case'\'':
           addChar();
           nextToken=ch;
           break;
    case'=':
           addChar();
           nextToken=ch;
           if(nextCh=='=')
           {
              getChar();
              addChar();
              nextToken=AEQU;
           }
           else if(nextCh=='>')
           {
              getChar();
              addChar();
              nextToken=LEQU;
           }
           break;
    case'>':
           addChar();
           nextToken=ch;
           if(nextCh==':')
           {
                getChar();
                addChar();
                nextToken=GEQU;
            }
           break;
    case'<':
           addChar();
           nextToken=ch;
           if(nextCh=='-')
           {
                getChar();
                addChar();
                nextToken=MEQU;
           }
           if(nextCh==':')
           {
                getChar();
                addChar();
                nextToken=KEQU;
           }
           if(nextCh=='%')
           {
                getChar();
                addChar();
                nextToken=NEQU;
           }
           break;
    case'/':
           addChar();
           nextToken=ch;
           if(nextCh=='*')
           {
                getChar();
                checkNote();
                nextToken=NOTE1;
           }
           else if(nextCh=='/')
           {
                getChar();
                checkNote2();
                nextToken=NOTE2;
           }
           break;
    case'(':
           nextToken=ch;
           if(nextCh!='"')
           {
                getChar();
                checkstring1();
			 nextToken=STRING;                
           }
           
    case EOF:
           addChar();
           nextToken=EOF;
    default:
           printf("ERRROR:unknown character'%c'.\n",ch);
           nextToken=ERROR;
    }
    return nextToken;
}

void checkKeywords(char *pword)
{
    int i=0;
    while(keywords[i]!=0)
    {
       char *pkeyword=keywords[i];
       if(strcmp(pword,pkeyword)==0)
       {
          nextToken=258+i;
          return;
       }
       i++;
    }
}

int lexer()
{
    lexLen=0;
    getNonBlank();
    switch(charClass)
    {
     case LETTER:
          addChar();
          getChar();
          while(charClass==LETTER||charClass==DIGIT)
          {
              addChar();
              getChar();
          }
          nextToken=ID;
          checkKeywords(lexeme);
          break;
     case DIGIT:
          addChar();
          getChar();
          while(charClass==DIGIT)
          {
             addChar();
             getChar();
          }
          if(nextChar=='.')
          {
             addChar();
             getChar();
             while(charClass==DIGIT){
                 addChar();
                 getChar();
             }
             nextToken=FLOAT;
          }
          else
          {
             nextToken=INT;
          }
          break;
     case UNKNOWN:
          checkSymbol(nextChar,next2Char);
          getChar();
          break;
     case EOF:
          nextToken=EOF;
          lexeme[0]='E';
          lexeme[1]='O';
          lexeme[2]='F';
          lexeme[3]=0;
          break;
     } 
     printf("<%6d,%s>\n",nextToken,lexeme);
     return nextToken;
}

int main(int argc,char* argv[])
{
     if(argc<2)
     {
         printf("ERROR:input file name is needed.\n");
         exit(0);
     }
     inFile=fopen(argv[1],"r");
     if(inFile==NULL)
     {
         printf("ERROR:can not open file.\n");
         exit(0);
     }
     
     getChar();
     while(nextToken!=EOF)
     {     
         lexer();
      }
      return 0;
}