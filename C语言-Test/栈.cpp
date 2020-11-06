#include<stdio.h> 
#define StackSize 100

typedef char DataType;
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;
 
void InitStack(SeqStack *S)    
/*将栈初始化为空栈只需要把栈顶指针top置为0*/
{
S->top=0;    /*把栈顶指针置为0*/
}
int StackEmpty(SeqStack S)   
/*判断栈是否为空，栈为空返回1，否则返回0*/
{
    if(S.top==0)            /*判断栈顶指针top是否为0*/
        return 1;          /*当栈为空时，返回1；否则返回0*/
    else
        return 0;
}
int GetTop(SeqStack S, DataType *e)   
/*取栈顶元素。将栈顶元素值返回给e，并返回1表示成功；否则返回0表示失败。*/
{
   if(S.top<=0)       /*在取栈顶元素之前，判断栈是否为空*/
{
    printf("栈已经空!\n");
    return 0;
}
else
{
    *e=S.stack[S.top-1];    /*在取栈顶元素*/
    return 1;
}
}
int PushStack(SeqStack *S,DataType e)   
/*将元素e进栈，元素进栈成功返回1，否则返回0.*/
{
if(S->top>=StackSize)             /*在元素进栈前，判断是否栈已经满*/
{
        printf("栈已满，不能进栈！\n");
        return 0;
}
else
{
        S->stack[S->top]=e;           /*元素e进栈*/
        S->top++;                    /*修改栈顶指针*/
        return 1;
}
}
int PopStack(SeqStack *S,DataType *e)
/*出栈操作。将栈顶元素出栈，并将其赋值给e。出栈成功返回1，否则返回0*/
{
    if(S->top<=0)     /*元素出栈之前，判断栈是否为空*/
    {
        printf("栈已经没有元素，不能出栈!\n");
        return 0;
    }
    else
{
    S->top--;            /*先修改栈顶指针，即出栈*/
        *e=S->stack[S->top];  /*将出栈元素赋值给e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*求栈的长度，即栈中元素个数，栈顶指针的值就等于栈中元素的个数*/
{
    return S.top;
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
////////////////////   main.c  ////////////////////////
#include<stdio.h>
#include<string.h>
typedef char DataType;
#include"SeqStack.h"
#define MaxSize 50
typedef struct/*操作数栈的类型定义*/
{
    float data[MaxSize];
    int top;                  
}OpStack;  
void TranslateExpress(char s1[],char s2[]);
float ComputeExpress(char s[]);
void main()
{
    char a[MaxSize],b[MaxSize];
    float f;
    printf("请输入一个算术表达式：\n");
    gets(a);
    printf("中缀表达式为：%s\n",a);
    TranslateExpress(a,b);
    printf("后缀表达式为：%s\n",b);
    f=ComputeExpress(b);
    printf("计算结果：%f\n",f);
}   
float ComputeExpress(char a[])
/*计算后缀表达式的值*/
{  
    OpStack S;
    int i=0,value;
    float x1,x2;
    float result;
    S.top=-1;
    while(a[i]!='\0')
    {
        if(a[i]!=' '&&a[i]>='0'&&a[i]<='9')/*如果当前字符是数字字符，则将其转换为数字并存入栈中*/
        {
            value=0;
            while(a[i]!=' ')
            {
                value=10*value+a[i]-'0';
                i++;
            }
            S.top++;
            S.data[S.top]=value;
        }      
        else            /*如果当前字符是运算符，则对栈中的数据进行求值，并将结果保存到栈中*/
        {
            switch(a[i])
            {
                 
            case '+':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x1+x2;
                S.top++;
                S.data[S.top]=result;
                break;
            case '-':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x2-x1;
                S.top++;
                S.data[S.top]=result;
                break;
            case '*':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x1*x2;
                S.top++;
                S.data[S.top]=result;
                break;
            case '/':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x2/x1;
                S.top++;
                S.data[S.top]=result;
                break;
            }
            i++;
        }
    }
     
    if(!S.top!=-1)
    {
        result=S.data[S.top];
        S.top--;
        if(S.top==-1)
            return result;
        else
        {
            printf("表达式错误");
            exit(-1);
        }
    }
}
void TranslateExpress(char str[],char exp[])   
/*将中缀表达式转换为后缀表达式*/
{
    SeqStack S;               
    char ch;   
    DataType e;
    int i=0,j=0;
    InitStack(&S);
    ch=str[i];                    
    i++;
    while(ch!='\0')               
    {
        switch(ch)
        {
        case'(':    /*左括号入栈*/  
            PushStack(&S,ch);
            break;
        case')':    /*如果当前字符是右括号，则将栈中的字符出栈，直到栈中的一个左括号出栈为止*/          
            while(GetTop(S,&e)&&e!='(')    
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PopStack(&S,&e);/*左括号出栈*/
            break;
        case'+':
        case'-':
            while(!StackEmpty(S)&&GetTop(S,&e)&&e!='(')/*如果当前字符是+号或-号，则将栈中字符出栈，直到遇到左括号为止*/
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PushStack(&S,ch);/*将当前字符入栈*/
            break;
        case'*':
        case'/':
            while(!StackEmpty(S)&&GetTop(S,&e)&&e=='/'||e=='*')/*如果当前字符是*号或者是/号，则将栈中字符出栈*/
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PushStack(&S,ch);   /*当前字符入栈*/
            break;
        case' ':
            break;
        default:                /*处理数字字符*/
            while(ch>='0'&&ch<='9')
            {
                exp[j]=ch;
                j++;
                ch=str[i];
                i++;
            }
            i--;
            exp[j]=' ';
            j++;
        }
        ch=str[i];
        i++;
    }
    while(!StackEmpty(S))
    {
        PopStack(&S,&e);
        exp[j]=e;
        j++;
    }
    exp[j]='\0';
}