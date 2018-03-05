#pragma once

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class History
{

public:
	History();
	~History();

	void add(string& customerData);
	void print();

private:
	
	vector<string> movieHistory;
};

#endif // !HISTORY_H
