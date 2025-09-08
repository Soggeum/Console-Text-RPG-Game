#pragma once
#include <map>
#include <string>

using namespace std;

template <typename T>
class LogManager {
private:
	map <string, T> logInput;
public:
	LogManager();
	void setLogInput(string logKey, T logValue);
	void displayLog();
};


