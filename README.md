SimpConGraf
===========

__Install__:<br />
	&emsp;1. Include "libSCG.h"<br />
	&emsp;2. Create libSCG object and give window size. Example: "libSCG SCG([widhth], [height], [debug mode "true" or "false"], [beautiful window "true" or "false"]);"<br />

__Usage__:<br />
	&emsp;SCG.execute("[command]");<br />

__Commands__:<br />
	&emsp;Draw Rectangle: "rect;[fill symbol];[write "true" if you want fill rectangle, else stay empty];[x1];[y1];[x2];[y2]"<br />
	&emsp;Draw Dot: "dot;[symbol];[x];[y]"<br />
	&emsp;Set foreground color: "fgcolor;[red];[green];[blue]"<br />
	&emsp;Set background color: "bgcolor;[red];[green];[blue]"<br />

__Log message construction__:<br />
	&emsp;SCG[ -Error code- ] >>> -Log message-<br />

__Error codes__:<br />
	&emsp;0 - succes<br />
	&emsp;1 - warning error<br />
	&emsp;2 - critical error<br />

_Make by VladikVT_<br />
_Version 1.0_<br />
