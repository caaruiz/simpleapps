#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
 
using namespace std;
 
#define MAX_HEX 0xFF
#define MAX_BUFFER 250
 
void errMsg(string msg)
{
	cout <<"ERROR: " << msg << endl; 
}

bool isHexValid(string inputString) 
{
	for (int i=0;i<inputString.size();i++){
		if(i == 1 && inputString[i] == 'x'){
			continue;
		}
		if(!isxdigit(inputString[i])){
			return false;
		}
	}
	return true; 
}

int getHex(string hexstr) 
{
    return (int)strtol(hexstr.c_str(), 0, 16);
}


int main()
{
	int hex_input  = 0x00;
	string input   = "";
	char tbuf [MAX_BUFFER] = "";
	int inverted   = 0x00;


	while(true){
		cout << "Enter Hex Value(Ex. 0xCA OR CA): ";
		getline(cin,input);

		//Check if input is in the correct format
		if(!isHexValid(input)){
			errMsg("Hex is not in valid format");
			continue;
		}

		if((hex_input  = getHex(input)) > MAX_HEX){
			sprintf(tbuf,"Enter Number Less Than Or Equal to %d",
							MAX_HEX);
			errMsg(tbuf);
			continue;
		}
		break;
	}

	inverted = ~hex_input;
	inverted = (inverted & MAX_HEX);
	cout << "Result: " << inverted << endl;
	return 0;
}
