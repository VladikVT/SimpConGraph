<h1 align="center">SimpConGraph</h1>

### Information:
SimpConGraph - C++ unix library for easy drawing in console

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
#### Commands:
Draw Rectangle: "rect;[symbol];[fill, "true" or nothing];[x1];[y1];[x2];[y2]" <br />
Draw Dot: "dot;[symbol];[x];[y]" <br />
Draw Circle: "circle;[symbol];[radius];[fill, "true" or nothing];[x];[y]" <br />
Draw Line: "line;[symbol];[x1];[y1];[x2];[y2]" <br />
Write Text: "text;[text];[lenght];[x];[y]" <br />
Set foreground color: "fgcolor;[red];[green];[blue]" <br />
Set background color: "bgcolor;[red];[green];[blue]" <br />
Clear window: "clear" <br />

#### Log message construction:
SCG[Error code] >>> [Log message]

#### Error codes:
0 - succes <br />
1 - warning error <br />
2 - critical error

### Links:
1. GitHub: https://github.com/VladikVT/SimpConGraph
2. NotABug: https://notabug.org/VladikVT/SimpConGraph


