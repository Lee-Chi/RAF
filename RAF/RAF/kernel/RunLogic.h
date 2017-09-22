#pragma once

#include <string>

namespace raf{ namespace kernel{

using std::string;

class Logic;

class RunLogic
{
public:
	RunLogic();
	virtual ~RunLogic();

	void setLogic(Logic*);
	Logic* getLogic();

	string getDescription();

	bool doAction();
private:
	Logic* logic;
};

class Logic
{
public:
	Logic(){}
	virtual ~Logic(){}

	virtual bool execute() = 0;

	virtual string getDescription() = 0;
};

class NullLogic: public Logic
{
public:
	NullLogic(){}
	~NullLogic(){}

	bool execute()
	{
		return false;
	}

	string getDescription()
	{
		return "NullLogic Please check.";
	}
};

}}
