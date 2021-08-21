#include <iostream>
#include <sstream>
#include <fstream>

#include <Windows.h>
#include <time.h>

using namespace std;

/**********************************************************************
 *  ConvertTo String function
 *
 **********************************************************************/
string intToStr(int num)
{
	ostringstream convert;
	convert << num;
	return convert.str();
}
string floatToStr(float num)
{
	ostringstream convert;
	convert << num;
	return convert.str();
}
string charToStr(char num)
{
	ostringstream convert;
	convert << num;
	return convert.str();
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

vector<string> tokenize(std::string const& str, const char delim)
{
	// construct a stream from the string
	std::stringstream ss(str);
	vector<string> out;
	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
	return out;
}

/*********************************************************************/

LPWSTR ConvertToLPWSTR(const std::string& s)
{
	LPWSTR ws = new wchar_t[s.size() + 1]; // +1 for zero at the end
	copy(s.begin(), s.end(), ws);
	ws[s.size()] = 0; // zero at the end
	return ws;
}

int writeText2OldFile(string filename, string text, bool newlineBeforeWrite, bool newlineAfterWrite)
{
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::app);
	if (newlineBeforeWrite)text = "\n" + text;
	if (newlineAfterWrite)text = text + "\n";
	ofs << text;

	ofs.close();
	return 0;
}
int countNumberLineInFile(string filename)
{
	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile(filename);

	while (std::getline(myfile, line))
		++number_of_lines;
	return number_of_lines;
}



// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
/*
const std::string getCurrentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);

	return buf;
}
*/