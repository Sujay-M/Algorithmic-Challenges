%{
#include<stdio.h>
#include<stdlib.h>
%}
%token R Y
%%
Str: S 
S: R S
| R Y S
| R Y Y S
|;
%%
yyerror()
{
	printf("NO");
	exit(0);

}
void main()
{
	yyparse();
	printf("YES\n");
}
