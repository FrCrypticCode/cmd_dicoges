#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <libusb-1.0/libusb.h>
#include "libs/fs.cpp"
#include "libs/dico.cpp"
#include "libs/switch.cpp"

using namespace std;

int main(){
	int c;
	Opts app;
	do{
		string entry;
		cout << ">> ";
		cin >> entry;
		c = app.cmd(entry);
		switch (c){	// Switch pour gérer la cmd
			case 0:
				return 0;
				break;
			case 1:
				look_at();
				break;
			case 2:{
				ges_dico();
				}
				break;
			default:
				cout << "Commande non reconnue" << endl;
				break;
		};
	}
	while (c!=0);
}