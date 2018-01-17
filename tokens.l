%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVETOKEN yylval.string = new std::string(yytext,yyleng)
#define TOKEN(t) (yyval.token=t)
extern "C" int yywrap(){}
%}

%%


[tn] ;
[a-zA-Z] [a-zA-Z0-9]* SAVETOKEN; return TOKENINDENTIFIER ;
[0-9]+ [0-9]* SAVETOKEN; return TOKENDOUBLE;

[0-9]+ SAVETOKEN; return TOKENINTEGERS;

"==" return TOKEN (DEQUAL);
"="  return TOKEN (EQUAL);
">"  return TOKEN (GRTHEN);
"<"  return TOKEN (LESSTHEN);
"<=" return TOKEN (LESSEQ);
">="return  TOKEN (MOREEQ);
"!="return  TOKEN (NTEQ);
")" return  TOKEN (RIGHTPAR);
"(" return  TOKEN (LEFTPAR);
"{" return  TOKEN (LEFTBRACE);
"}" return  TOKEN (RIGHTBRACE);
"." return  TOKEN (DOT);
"," return  TOKEN (COMMA);
"*" return  TOKEN (MULT);
"+" return  TOKEN (PLUS);
"-" return  TOKEN (MINUS);
"/" return  TOKEN (DIVISION);

. printf ("token not identified");

yyterminate();
%%

