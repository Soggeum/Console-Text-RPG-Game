#pragma once
#include <map>
#include <string>

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
};


