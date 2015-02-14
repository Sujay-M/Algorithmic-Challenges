%{
	#include"y.tab.h"
%}
%%
R return R;
Y return Y;
. return yytext[0];
\n return 0;
%%