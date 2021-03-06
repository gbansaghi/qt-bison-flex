%{
#include "common.h"

int yylex();
void yyerror(const char *s);

elements_t parsedElements;
int lineno;

%}

%defines "parser.h"
%output "parser.cpp"
%error-verbose

%union {
    int v_int;
}

%initial-action
{
    lineno = 1;
    parsedElements.clear();
}

%token HELLO GOODBYE MAX ALIGN
%token LEFT RIGHT CENTER
%token ENDL

%token INTEGER
%type <v_int> INTEGER alignment

%%

program:
    HELLO
    endls
    statements
    endls
    GOODBYE
    opt_endls   {}
    ;

endls:
    endls endl
    |
    endl
    ;

endl:
    ENDL    { ++lineno; }
    ;

opt_endls:
    endls
    |
    %empty
    ;

statements:
    statements endls statement
    |
    statement
    ;

statement:
    MAX INTEGER ALIGN alignment    { parsedElements << ParseElement{$2, static_cast<Qt::AlignmentFlag>($4)}; }
    ;

alignment:
    LEFT    { $$ = static_cast<int>(Qt::AlignLeft); }
    |
    RIGHT   { $$ = static_cast<int>(Qt::AlignRight); }
    |
    CENTER  { $$ = static_cast<int>(Qt::AlignCenter); }
    ;

%%

void yyerror(const char *s) {
    yyclearin;
    throw ParserException{lineno, QString(s)};
}
