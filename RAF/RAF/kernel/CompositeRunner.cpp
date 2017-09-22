#include "CompositeRunner.h"

namespace raf{ namespace kernel{

CompositeRunner::CompositeRunner()
{
}

CompositeRunner::~CompositeRunner()
{
	if(isContain())
	{
		for(vector<Runner*>::iterator it = runners.begin(); it != runners.end(); ++it)
		{
			if((*it) != NULL)
			{
				delete (*it);
				(*it) = NULL;
			}
		}
		runners.clear();
	}
	
}

void CompositeRunner::add(Runner* runner)
{
	runners.push_back(runner);
}

int CompositeRunner::size() const
{
	return runners.size();
}

bool CompositeRunner::isEmpty() const
{
	return runners.size() <= 0;
}

bool CompositeRunner::isContain() const
{
	return !isEmpty();
}

Runner* CompositeRunner::getRunner(int idx) const
{
	return (idx >= 0 && idx < (int)(runners.size()))? runners[idx]: NULL;
}

vector<Runner*> CompositeRunner::getRunners() const
{
	return runners;
}

bool CompositeRunner::_init()
{
	eraseDeadRunner();

	for(vector<Runner*>::iterator it = runners.begin(); it != runners.end(); ++it)
	{
		if(!(*it)->initialize())
			return false;
	}
	return true;
}

bool CompositeRunner::_run()
{
	eraseDeadRunner();

	for(vector<Runner*>::iterator it = runners.begin(); it != runners.end(); ++it)
	{	
		if(!(*it)->run())
			return false;
	}
	return true;
}

bool CompositeRunner::_final()
{
	eraseDeadRunner();

	for(vector<Runner*>::iterator it = runners.begin(); it != runners.end(); ++it)
	{
		if(!(*it)->finalize())
			return false;
	}
	return true;
}

void CompositeRunner::eraseDeadRunner()
{
	for(vector<Runner*>::iterator it = runners.begin(); it != runners.end();)
	{
		if((*it)->isDead())
		{
			(*it)->finalize();
			delete *it;
			it = runners.erase(it);
		}
		else
			++it;
	}
}

string CompositeRunner::_getDescription()
{
	return "CompositeRunner";
}

}}