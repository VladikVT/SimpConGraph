#include "libSCG.h"

libSCG::libSCG(int sX, int sY, bool debug, bool btflWindow)
	: sizeX(sX), sizeY(sY), debug(debug), btflWindow(btflWindow)
{
	clearScreen;
	saveCursor;
	if ( btflWindow == true ) { cout << "\033[" << sizeY + 3 << ";" << 0 << "H"; }
	else { cout << "\033[" << sizeY + 1 << ";" << 0 << "H"; }
	printLogMsg("Start SCG", 0); 
	printLogMsg("Window size: " + to_string(sizeX) + "x" + to_string(sizeY), 0);
	loadCursor;
	cout << "\033[" << 0 << ";" << 0 << "H";
	drawWindow();

	if (debug == false)
	{
		if ( btflWindow == true ) { cout << "\033[" << sizeY + 3 << ";" << 0 << "H"; }
		else { cout << "\033[" << sizeY + 1 << ";" << 0 << "H"; }

		saveCursor;
	}

	loadCursor;
}

libSCG::~libSCG()
{
	printLogMsg("Stop SCG", 0);
}

// PUBLIC //

void libSCG::execute(string command)
{
	string dlmtr = ";";
	size_t pos = 0;
	string token;
	string cmdCopy = command;
	
	int atrCount = 10;
	string cmdAttributes[atrCount];
	int counter = 0;
	
	while ((pos = command.find(dlmtr)) != string::npos)
	{
		token = command.substr(0, pos);
		if (counter < atrCount) 
		{ 
			cmdAttributes[counter] = token; 
		} else {
			printLogMsg("Allowed count of attributes in command '" + cmdCopy + "' has been exceeded", 2);
			return ;
		}
		command.erase(0, pos + dlmtr.length());
		counter++;
	}
	cmdAttributes[counter++] = command;
	// RECTANGLE //
	if (cmdAttributes[0] == "rect")
	{
		try {
			rectangle(cmdAttributes[1],
				cmdAttributes[2] == "true",
				stoi(cmdAttributes[3]), 
				stoi(cmdAttributes[4]),
				stoi(cmdAttributes[5]),
				stoi(cmdAttributes[6]));
		} catch (...) {
			printLogMsg("Command '" + cmdCopy + "' got not correct data!", 2);
			return ;
		}
	}
	// CHANGE FOREGRAUND COLOR //
	else if (cmdAttributes[0] == "fgcolor")
	{
		try {
			setColor(BGcolor[0], BGcolor[1], BGcolor[2], 
				stoi(cmdAttributes[1]),
				stoi(cmdAttributes[2]),
				stoi(cmdAttributes[3]));
		} catch (...) {
			printLogMsg("Command '" + cmdCopy + "' got not correct data!", 2);
			return ;
		}
	} 
	// CHANGE BACKGROUND COLOR //
	else if (cmdAttributes[0] == "bgcolor")
	{
		try {
			setColor(stoi(cmdAttributes[1]),
				stoi(cmdAttributes[2]),
				stoi(cmdAttributes[3]),
				FGcolor[0], FGcolor[1], FGcolor[2]);
		} catch (...) {
			printLogMsg("Command '" + cmdCopy + "' got not correct data!", 2);
			return ;
		}
	} 
	// DOT //
	else if (cmdAttributes[0] == "dot")
	{
		try {
			rectangle(cmdAttributes[1],
				true,
				stoi(cmdAttributes[2]), 
				stoi(cmdAttributes[3]),
				stoi(cmdAttributes[2]),
				stoi(cmdAttributes[3]));
		} catch (...) {
			printLogMsg("Command '" + cmdCopy + "' got not correct data!", 2);
			return ;
		}

	}
}

// PRIVATE //

void libSCG::drawWindow()
{
	if (btflWindow == true)
	{
		for (int y = 0; y < sizeY + 2; y++)
		{
			for (int x = 0; x < sizeX + 2; x++)
			{
				if (y == 0 || y == sizeY + 1)
				{
					cout << "==";
				} else if (x == 0 || x == sizeX + 1) {
					cout << "||";
				} else {
					cout << "  ";
				}
			}
			cout << endl;
		}
	} else {
		for (int y = 0; y < sizeY; y++)
		{
			for (int x = 0; x < sizeX; x++)
			{
				cout << "[]";
			}
			cout << endl;
		}
	}	
}

void libSCG::printLogMsg(string msg, int err)
{
	if (debug == true || err != 0)
	{
		cout << "SCG[" << err << "] >>> " << msg << endl;
		saveCursor;
	}
}

void libSCG::writeSymbol(string symbol, int x, int y)
{
	if (x < sizeX && y < sizeY)
	{
		if (btflWindow == true) { cout << "\033[" << y + 2 << ";" << x * 2 + 3 << "H"; }
		else { cout << "\033[" << y  + 1 << ";" << x * 2 + 1 << "H"; }
		cout << "\033[38;2;" << FGcolor[0] << ";" << FGcolor[1] << ";" << FGcolor[2] << "m";
		cout << "\033[48;2;" << BGcolor[0] << ";" << BGcolor[1] << ";" << BGcolor[2] << "m";
		cout << symbol;
		cout << "\033[0;0m";
		loadCursor;
	}
}

void libSCG::rectangle(string symbol, bool fill, int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || y1 < 0 || x2 >= sizeX || y2 >= sizeY)
	{
		printLogMsg("Rectangle out of window", 1);
		return ;
	}
	if (x1 > x2 || y1 > y2)
	{
		printLogMsg("Not correct rectangle coordinates", 1);
		return ;
	}
	
	if (fill == true)
	{
		for (int y = y1; y <= y2; y++)
		{
			for (int x = x1; x <= x2; x++)
			{
				writeSymbol(symbol, x, y);
			}
		}
	} else {
		for (int y = y1; y <= y2; y++)
		{
			for (int x = x1; x <= x2; x++)
			{
				if (y == 0 || x == 0 || y == y2 || x == x2)
				{
					writeSymbol(symbol, x, y);
				}
			}
		}
	}
	printLogMsg("Draw rectangle", 0);
}

void libSCG::setColor(int Br, int Bg, int Bb, int Fr, int Fg, int Fb)
{
	BGcolor[0] = Br;
	BGcolor[1] = Bg;
	BGcolor[2] = Bb;
	FGcolor[0] = Fr;
	FGcolor[1] = Fg;
	FGcolor[2] = Fb;
	printLogMsg("Color set", 0);
}


