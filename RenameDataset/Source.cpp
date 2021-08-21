#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "Gspecial.h"
#include <conio.h>
using namespace std;
using namespace std::experimental::filesystem::v1;

string getFolderName(string path)
{
	string wasteName = "";
	vector<string> splitedPath = tokenize(path, '\\');
	if (splitedPath.size() > 1)
	{
		wasteName = splitedPath[splitedPath.size() - 2];
		//cout << "\nWasteName : " << wasteName;
	}
	return wasteName;
}


string getOnlyFileName(string path)
{
	string retString = "";
	for (int i = path.size() - 1; i >= path.size() - 10; i--)
	{
		if (path[i] == '.')
		{
			path.pop_back();
			break;
		}
	}
	for (int i = path.size() - 1; i >= path.size() - 10; i--)
	{
		if (path[i] == '\\')
		{
			retString.insert(0, path, i, path.size() - i);
			break;
		}
	}
	return retString;
}

string getFileExtension(string path)
{
	string retString = "";
	for (int i = path.size() - 1; i >= path.size() - 10; i--)
	{
		if (path[i] == '.')
		{
			retString.insert(0, path, i, path.size() - i);
			break;
		}
	}
	return retString;
}

int main(int argc, char *argv[]) {
	string exeFilename = argv[0];
	std::vector <string> listFiles;
	std::vector <string> listXMLFiles;
	string folderName = getFolderName(exeFilename);
	string path = argv[0];
	for (int p = path.size()-1; p >= 1; p--)
	{
		//cout << path[p];
		if (path[p] == '\\') 
		{
			break;
		}
		else 
		{ 
			path.pop_back();
		}
	}
	cout << "Rename File in Path -> " << path <<"\n";
	cout << "\n\nLoad File...........\n";
	//execlude exe file
	//Insert ".JPG"
	for (const auto& entry : directory_iterator(path))
	{ 
		string filename = entry.path().string();
		if (filename == exeFilename) continue;
		if (filename[filename.size() - 3] == 'J' && filename[filename.size() - 2] == 'P' && filename[filename.size() - 1] == 'G')
		{
			cout << filename << endl;
			listFiles.push_back(filename);
		}
	}
	//execlude exe file
	//Insert ".jpg" and another
	for (const auto& entry : directory_iterator(path))
	{
		string filename = entry.path().string();
		if (filename == exeFilename) continue;
		if (filename[filename.size() - 3] == 'j' && filename[filename.size() - 2] == 'p' && filename[filename.size() - 1] == 'g')
		{
			listFiles.push_back(filename);
			cout << filename << endl;
		}
	}
	
	for (const auto& entry : directory_iterator(path))
	{
		string filename = entry.path().string();
		if (filename == exeFilename) continue;
		if (filename[filename.size() - 3] == 'x' && filename[filename.size() - 2] == 'm' && filename[filename.size() - 1] == 'l')
		{
			listXMLFiles.push_back(filename);
			cout << filename << endl;
		}
	}
	cout << "\n\nRename File JPG...........\n";
	//list file JPG and jpg
	for (u_int i=0;i<listFiles.size();i++)
	{
		cout << listFiles[i];
		string fileExtension = getFileExtension(listFiles[i]);
		string newFileName = path + folderName + "_" + intToStr(i+1)+fileExtension;
		cout << "  ->  " << folderName + "_" + intToStr(i + 1) + fileExtension;
		int Ret = rename(listFiles[i].c_str(), newFileName.c_str());
		if(Ret==0) cout << " OK!" << endl;
		else cout << " Error!" << endl;
	}
	cout << "\n\nRename File XML...........\n";
	//list file JPG and jpg
	for (u_int i = 0; i < listXMLFiles.size(); i++)
	{
		cout << listXMLFiles[i];
		string fileExtension = getFileExtension(listXMLFiles[i]);
		if(getOnlyFileName(fileExtension)) //matched with old file name
		string newFileName = path + folderName + "_" + intToStr(i + 1) + fileExtension;
		cout << "  ->  " << folderName + "_" + intToStr(i + 1) + fileExtension;
		int Ret = rename(listFiles[i].c_str(), newFileName.c_str());
		if (Ret == 0) cout << " OK!" << endl;
		else cout << " Error!" << endl;
	}

	_getch();
	return EXIT_SUCCESS;
}