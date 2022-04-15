SimpConGraph
============

### Information:
SimpConGraph - c++ unix library for easy drawing in console

### Motivation:
I often need to draw something in the console, so on order 
not to write the same thing in every project, i created this library	

### Usage:
1. Include "libSCG.h"
2. Add libSCG object in your project
> libSCG SCG([widhth], [height], [debug mode "true" or "false"], [beautiful window "true" or "false"]);"
3. Execute command
> SCG.execute("[command]");

### Mini documentation:
__Commands__:
Draw Rectangle: "rect;[fill symbol];[write "true" if you want fill rectangle, else stay empty];[x1];[y1];[x2];[y2]"
Draw Dot: "dot;[symbol];[x];[y]"
Set foreground color: "fgcolor;[red];[green];[blue]"
Set background color: "bgcolor;[red];[green];[blue]"

__Log message construction__:
SCG[Error code] >>> [Log message]

__Error codes__:
0 - succes
1 - warning error
2 - critical error


