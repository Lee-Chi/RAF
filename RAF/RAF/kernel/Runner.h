#pragma once

#include <string>

namespace raf{ namespace kernel{

using std::string;

enum RunnerState
{
	DEAD = 0,
	ALIVE
};

class Runner
{
public:
	Runner();
	virtual ~Runner();

	bool isDead() const;

	void kill(){state = DEAD;}

	string getDescription();

	bool initialize();
	bool run();
	bool finalize();

protected:
	virtual string _getDescription() = 0;
	virtual bool _init() = 0;
	virtual bool _run() = 0;
	virtual bool _final() = 0;

private:
	RunnerState state;
};

}}