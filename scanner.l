%{
#include <cstdlib>
#include "parser.h"

int yylex();
void yyerror(const char *s);
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

%%

#.*         { /* comment */ }

HELLO       { return HELLO; }
GOODBYE     { return GOODBYE; }
max         { return MAX; }
align       { return ALIGN; }
left        { return LEFT; }
right       { return RIGHT; }
center      { return CENTER; }

[0-9]+      { yylval.v_int = atoi(yytext); return INTEGER; }

[ \t]       { /* ignore whitespace */ }
\n          { return ENDL;  }

.           { yyerror("invalid character"); }

%%
