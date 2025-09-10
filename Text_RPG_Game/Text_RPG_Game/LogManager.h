#pragma once
#include <map>
#include <string>
#include <iostream>

using namespace std;

class LogManager {
private:
	map <string, string> logInput;
public:
	LogManager();
	void setLogInput(string logKey);
	void setLogInput(string logKey, string logValue);
	void setLogInput(string logKey, int logValue);
	void displayLog();
	void displayAllLog();
};


