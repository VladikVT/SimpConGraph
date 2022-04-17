#include <iostream>
#include "../libSCG.h"

using namespace std;

int main()
{
	libSCG SCG(11, 11, false, true);
	
	SCG.execute("rect;  ;true;0;0;10;10");
	SCG.execute("fgcolor;0;255;255");
	SCG.execute("bgcolor;255;0;0");
	
	SCG.execute("line;SS;1;3;3;3");
	SCG.execute("line;SS;1;3;1;5");
	SCG.execute("line;SS;1;5;3;5");
	SCG.execute("line;SS;3;5;3;7");
	SCG.execute("line;SS;1;7;3;7");

	SCG.execute("fgcolor;255;0;255");
	SCG.execute("bgcolor;0;255;0");

	SCG.execute("line;CC;4;3;6;3");
	SCG.execute("line;CC;4;3;4;7");
	SCG.execute("line;CC;4;7;6;7");

	SCG.execute("fgcolor;255;255;0");
	SCG.execute("bgcolor;0;0;255");

	SCG.execute("line;GG;7;3;9;3");
	SCG.execute("line;GG;7;3;7;7");
	SCG.execute("line;GG;7;7;9;7");
	SCG.execute("dot;GG;9;6");

	return 0;
}
