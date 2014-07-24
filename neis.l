%{
#include "neis.tab.h"
#include "tree.h"
#include <string.h>
%}

%pointer

%%
[ \n\t]           ;                   // white space
[0-9]+            {yylval.ival = atoi(yytext); return NUM;}   // integers
int               {return TINT;}
float             {return TFLOAT;}
char              {return TCHAR;}
void              {return TVOID;}
double            {return TDOUBLE;}
return            {return TRETURN;}    // return
if                {return IF;}        // if
else              {return ELSE;}      // else
while             {return WHILE;}     // while
for               {return FOR;}       // for
&&                {return TAND;}       // and
\|\|              {return TOR;}        // or
"<="              {return TLE;}        // less or equal
">="              {return TGE;}        // greater or equal
"<"               {return TLT;}        // less than
">"               {return TGT;}        // greater than
"=="              {return TEQ;}        // equal to
"!="              {return TNE;}        // not equal to
[a-zA-Z]+         {yylval.name =  (char*)yytext; return ID;} // function/variable name
.                 {return yytext[0];} // match all single characters
\/\/.*            ; // ignore comments
\/\*(.*\n)*.*\*\/ ; // ignore comments
%%
