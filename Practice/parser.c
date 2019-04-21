#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
//#include "tokens.h"
//#include "scanner.c"

void program();
void block();
void vars();
void expr();
void A();
void N();
void M();
void R();
void stats();
void mStat();
void stat();
void in();
void out();
void iff();
void K();
void J();
void loop();
void assign();
void RO();
void RO1();
void RO2();

struct tokens tkn;

void parser()
{
	//struct tokens tkn;
	tkn = scanner();
	//cout << tkn.ID << endl;
	program();

	if (tkn.ID == "EOFTKN")
	{
		cout << "WAHOO YOU MADE IT!!!! " << endl;
		//continue parse
	}
	else
	{
		cout << "ERROR: NO EOF TOKEN" << endl;
		exit(0);
	}


}

void program()
{
	vars();
	block();
}

void block()
{
	if(tkn.ID == "voidTKN")
	{
		tkn = scanner();
		vars();
		stats();
		if(tkn.ID == "returnTKN")
		{
			tkn = scanner();
			return;
		}
		else
		{
			cout << "ERROR FOR BLOCK(): NOT returnTKN " << endl;
			exit(0);
		}
	}
	else
	{
		cout << "ERROR FOR BLOCK(): NOT voidTKN " << endl;
		exit(0);
	}
	
}

void vars()
{
	if (tkn.ID == "varTKN")
	{
		tkn = scanner();
		if(tkn.ID == "IDTKN")
		{
			tkn = scanner();
			if(tkn.ID == "ColonTKN")
			{
				tkn = scanner();
				if(tkn.ID == "IntegerTKN")
				{
					tkn = scanner();
					vars();
					return;
				}
				else
				{
					cout << "ERROR FOR VARS(): NOT intTKN " << endl;
					exit(0);
				}
			}
			else
			{
				cout << "ERROR FOR VARS(): NOT ColonTKN " << endl;
				exit(0);
			}
		}
		else
		{
			cout << "ERROR FOR VARS(): NOT IDTKN " << endl;
			exit(0);
		}
	}
	else
	{
		return;
	}
}

void expr()
{
	A();
	if(tkn.ID == "AdditionTKN")
	{
		tkn = scanner();
		expr();
		return;
	}
	else if(tkn.ID == "SubtractionTKN")
	{
		tkn = scanner();
		expr();
		return;
	}
	else
	{
		return;
	}
}

void A()
{
	N();
	if(tkn.ID == "DivisionTKN")
	{
		tkn = scanner();
		A();
		return;
	}
	else
	{
		return;
	}
}

void N()
{
	M();
	if(tkn.ID == "MultiplicationTKN")
	{
		tkn = scanner();
		N();
		return;
	}
	else
	{
		return;
	}
}

void M()
{
	if(tkn.ID == "ModulosTKN")
	{
		tkn = scanner();
		M();
		return;
	}
	else
	{
		R();
		return;
	}
}

void R()
{
	if(tkn.ID == "LeftParenthesisTKN")
	{
		tkn = scanner();
		expr();
		if(tkn.ID == "RightParenthesisTKN")
		{
			tkn = scanner();
			return;
		}
		else
		{
			cout << "ERROR FOR R(): NOT RightParenthesisTKN " << endl;		
			exit(0);
		}
	}
	else if(tkn.ID == "IDTKN")
	{
		tkn = scanner();
		return;
	}
	else if(tkn.ID == "IntegerTKN")
	{
		tkn = scanner();
		return;
	}
	else
	{
		cout << "ERROR FOR R(): NOT A VALID TKN " << endl;
		exit(0);
	}
}

void stats()
{
	stat();
	if(tkn.ID == "SemiColonTKN")
	{
		tkn = scanner();
		mStat();
		return;
	}
	else
	{
		cout << "ERROR FOR STATS(): NO SemiColonTKN " << endl;
		exit(0);
	}
}

void mStat()
{
	if(tkn.ID == "scanTKN" || tkn.ID == "printTKN" || tkn.ID == "voidTKN" || tkn.ID == "condTKN" || tkn.ID == "iterTKN" || tkn.ID == "IDTKN")
	{
		stat();
		if(tkn.ID == "SemiColonTKN")
		{
			tkn = scanner();
			mStat();
			return;
		}
		else
		{
			cout << "ERROR FOR mStat(): NO SemiColonTKN " << endl;
			exit(0);
		}
	}
	else
	{
		return;
	}
}

void stat()
{
	if(tkn.ID == "scanTKN")
	{
		in();
		return;
	}
	else if(tkn.ID == "printTKN")
	{
		out();
		return;
	}	
	else if(tkn.ID == "voidTKN")
	{
		block();
		return;
	}
	else if(tkn.ID == "condTKN")
	{
		iff();
		return;
	}
	else if(tkn.ID == "iterTKN")
	{
		loop();
		return;
	}
	else if(tkn.ID == "IDTKN")
	{
		assign();
		return;
	}
	else
	{
		cout << "ERROR FOR STAT(): NOT A VALID TKN " << endl;
		exit(0);
	}
}

void in()
{
	if(tkn.ID == "scanTKN")
	{
		tkn = scanner();
		if(tkn.ID == "IDTKN")
		{
			tkn = scanner();
			return;
		}
		else
		{
			cout << "ERROR FOR IN(): NOT IDTKN " << endl;
			exit(0);
		}
	}
	else
	{
		cout << "ERROR FOR IN(): NOT scanTKN" << endl;
		exit(0);
	}
}

void out()
{
	if(tkn.ID == "printTKN")
	{
		tkn = scanner();
		expr();
		return;
	}
	else
	{
		cout << "ERROR FOR OUT(): NOT printTKN " << endl;
		exit(0);
	}
}

void iff()
{
	if(tkn.ID == "condTKN")
	{
		tkn = scanner();
		if(tkn.ID == "LeftBracketTKN")
		{
			tkn = scanner();
			K();
			if(tkn.ID == "RightBracketTKN")
			{
				tkn = scanner();
				stat();
				return;
			}
			else
			{
				cout << "ERROR FOR IFF(): NOT RightBracketTKN " << endl;
				exit(0);
			}
		}
		else
		{
			cout << "ERROR FOR IFF(): NOT LeftBracketTKN " << endl;
			exit(0);
		}
	}
	else
	{
		cout << "ERROR FOR IFF(): NOT condTKN " << endl;
		exit(0);
	}
}

void K()
{
	expr();
	J();
	return;
}

void J()
{
	RO();
	expr();
	return;
}

void loop()
{
	if(tkn.ID == "iterTKN")
	{
		tkn = scanner();
		if(tkn.ID == "LeftBracketTKN")
		{
			tkn = scanner();
			K();
			if(tkn.ID == "RightBracketTKN")
			{
				tkn = scanner();
				stat();
				return;
			}
			else
			{
				cout << "ERROR FOR loop(): NOT RightBracketTKN " << endl;
				exit(0);
			}
		}
		else
		{
			cout << "ERROR FOR loop(): NOT LeftBracketTKN " << endl;
			exit(0);
		}
	}
	else
	{
		cout << "ERROR FOR loop(): NOT iterTKN " << endl;
		exit(0);
	}
}

void assign()
{
	if(tkn.ID == "IDTKN")
	{
		tkn = scanner();
		if(tkn.ID == "AssignmentTKN")
		{
			tkn = scanner();
			expr();
			return;
		}
		else
		{
			cout << "ERROR FOR assign(): NOT assignmentTKN " << endl;
			exit(0);
		}
	}
	else
	{
		cout << "ERROR FOR assign(): NOT IDTKN " << endl;
		exit(0);
	}
}

void RO()
{
	if(tkn.ID == "LessThanTKN")
	{
		tkn = scanner();
		RO1();
		return;
	}
	else if(tkn.ID == "AssignmentTKN")
	{
		tkn = scanner();
		RO2();
		return;
	}
	else if(tkn.ID == "GreaterThanTKN")
	{
		tkn = scanner();
		return;
	}
	else
	{
		cout << "ERROR FOR RO(): NOT a valid TKN! " << endl;
		exit(0);
	}
}

void RO1()
{
	if(tkn.ID == "GreaterThanTKN")
	{
		tkn = scanner();
		return;
	}
	else
	{
		return;
	}
}

void RO2()
{
	if(tkn.ID == "LessThanTKN")
	{
		tkn = scanner();
		return;
	}
	else if(tkn.ID == "GreaterThanTKN")
	{
		tkn = scanner();
		return;
	}
	else
	{
		return;
	}
}
