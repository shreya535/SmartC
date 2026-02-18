GNU nano 7.2                                                                                                                                                                                                                        preprocessor.l
%{
#include <stdio.h>
#include <string.h>

FILE *yyin;
FILE *out;

#define MAX_MACROS 200

char names[MAX_MACROS][50];
char values[MAX_MACROS][200];
int count = 0;

int find(char *id){
    for(int i=0;i<count;i++)
        if(strcmp(id,names[i])==0)
            return i;
    return -1;
}

void expand(char *text){
    int idx = find(text);
    if(idx==-1){
        fprintf(out,"%s",text);
        return;
    }
    if(strcmp(values[idx],text)==0){
        fprintf(out,"%s",text);
        return;
    }
    expand(values[idx]);
}
%}

%x COMMENT STRING CHARLIT
ID [A-Za-z_][A-Za-z0-9_]*

%%

^[ \t]*#define[ \t]+{ID}[ \t]+.* {
    char n[50], v[200];
    sscanf(yytext,"#define %s %[^/]",n,v);

    int idx=find(n);
    if(idx!=-1){
        strcpy(values[idx],v);
    } else if(count<MAX_MACROS){
        strcpy(names[count],n);
        strcpy(values[count],v);
        count++;
    }
}

^[ \t]*#undef[ \t]+{ID} {
    char n[50];
    sscanf(yytext,"#undef %s",n);
    int idx=find(n);
    if(idx!=-1){
        for(int i=idx;i<count-1;i++){
            strcpy(names[i],names[i+1]);
            strcpy(values[i],values[i+1]);
        }
        count--;
    }
}

"//".* { fprintf(out,"%s",yytext); }
"/*" { BEGIN(COMMENT); fprintf(out,"/*"); }
<COMMENT>"*/" { BEGIN(INITIAL); fprintf(out,"*/"); }
<COMMENT>\n { fprintf(out,"\n"); }
<COMMENT>. { fprintf(out,"%s",yytext); }

\" { BEGIN(STRING); fprintf(out,"\""); }
<STRING>\" { BEGIN(INITIAL); fprintf(out,"\""); }
<STRING>\n { fprintf(out,"\n"); }
<STRING>. { fprintf(out,"%s",yytext); }

\' { BEGIN(CHARLIT); fprintf(out,"\'"); }
<CHARLIT>\' { BEGIN(INITIAL); fprintf(out,"\'"); }
<CHARLIT>\n { fprintf(out,"\n"); }
<CHARLIT>. { fprintf(out,"%s",yytext); }

{ID} { expand(yytext); }

\n { fprintf(out,"\n"); }
. { fprintf(out,"%s",yytext); }

%%
int main(){
    printf("Running in current folder...\n");

    yyin = fopen("input.c","r");
    if(!yyin){
        perror("Cannot open input.c");
        return 1;
    }

    out = fopen("output.c","w");
    if(!out){
        perror("Cannot create output.c");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);

    printf("Done. Check output.c\n");
    return 0;
}
int yywrap()
{
return 1;}
