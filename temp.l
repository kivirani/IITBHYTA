%option noyywrap
%option yylineno
%{
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#include "y.tab.h"
//extern int yylval;
void yyerror(char *);
unsigned int line_number=1;
char* outchar;
char* mychars;
%}
DIGIT      [0-9]
LETTER     [a-zA-Z]

%%
"automaton" {return AUTOMATON;}
"end" {return END;}
"state_var" {return INTERNAL_VAR;}
"contr_var" {return INTERNAL_VAR;}
"input_var" {return EXTERNAL_VAR;}
"parameter" {return PARAMETER;}
"synclabs" {return SYNCLABS;}
"initially" {return INITIALLY;}
"loc" {return LOC;}
"while" {return WHILE;}
"wait"  {return WAIT;}
"when" {return WHEN;}
"do"   {return DO;}
"sync" {return SYNC;}
"goto" {return GOTO;}
"true"  {return TRUE;}
"True"  {return TRUE;}
"TRUE"  {return TRUE;}
"false"  {return FALSE;}
"False"  {return FALSE;}
"FALSE"  {return FALSE;}


"==" {return EQ;}
">=" {return GE;}
"<=" {return LE;}
"'"  {return PRIM;}
":=" {return ASSIGN;}


([0-9]+)(("."[0-9]+)?)((([eE])([+-]?)([0-9]+))?)  {     
							//cout<<"Digit trying to recognize"<<endl;
							yylval.str =new string(""); 
							yylval.str->append(yytext,yytext+strlen(yytext)); 
							//cout<<"Digit is "<<*(yylval.str)<<" "<<yylval.str->length()<<endl;
							return INT;
						  } 

  
[-+<>*/&|(){}:;,.=!]|"["|"]" {return *yytext;}

(["$""?"a-zA-Z]|[_])("$"|"?"|[a-zA-Z]|[0-9]|[_]|[~])* { 
							yylval.str =new string(""); 
							yylval.str->append(yytext,yytext+strlen(yytext)); 
							//cout<<"Identifier:"<<*(yylval.str)<<" "<<yylval.str->length()<<endl;
							return IDENT; 
						      }

"/*"([^*]|("*"+[^*/]))*"*"+"/" /* skip comment */
"//".*                         /* skip comment XS*/
"--".*                         /* skip comment */


\"(.*)\" {
    yylval.str = new string("");
    yylval.str->append(yytext+1,yytext+strlen(yytext));    
    return STRING_TEXT;
}

[\n] { ++line_number; 
cout << line_number << endl << flush;
}

[ \t\r]

. { 
    outchar=strdup(yytext);
    yyerror(outchar);
  }

%%

