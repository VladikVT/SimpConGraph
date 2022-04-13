SimpConGraf
===========

__Install__:
	1. Include "libSCG.h"
	2. Create libSCG object and give window size. Example: "libSCG SCG([widhth], [height]);"

__Usage__:
	SCG.execute("[command]");

__Commands__:
	Draw Rectangle: "rect;[fill symbol];[write "true" if you want fill rectangle, else stay empty];[x1];[y1];[x2];[y2]"
	Draw Dot: "dot;[symbol];[x];[y]"
	Set foreground color: "fgcolor;[red];[green];[blue]"
	Set background color: "bgcolor;[red];[green];[blue]"

__Log message construction__:
	SCG[ -Error code- ] >>> -Log message-

__Error codes__:
	0 - succes
	1 - warning error
	2 - critical error

_Make by VladikVT_
_Version 1.0_
