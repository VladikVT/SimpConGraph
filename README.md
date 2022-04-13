SimpConGraf
===========

__Install__:<br />
	1. Include "libSCG.h"<br />
	2. Create libSCG object and give window size. Example: "libSCG SCG([widhth], [height]);"<br />

__Usage__:<br />
	SCG.execute("[command]");<br />

__Commands__:<br />
	Draw Rectangle: "rect;[fill symbol];[write "true" if you want fill rectangle, else stay empty];[x1];[y1];[x2];[y2]"<br />
	Draw Dot: "dot;[symbol];[x];[y]"<br />
	Set foreground color: "fgcolor;[red];[green];[blue]"<br />
	Set background color: "bgcolor;[red];[green];[blue]"<br />

__Log message construction__:<br />
	SCG[ -Error code- ] >>> -Log message-<br />

__Error codes__:<br />
	0 - succes<br />
	1 - warning error<br />
	2 - critical error<br />

_Make by VladikVT_<br />
_Version 1.0_<br />
