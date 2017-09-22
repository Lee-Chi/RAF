#include "Runner.h"

namespace raf{ namespace kernel{

Runner::Runner(): state(ALIVE)
{
}

Runner::~Runner()
{
}

bool Runner::isDead() const
{
	return (state == DEAD)? true: false;
}

string Runner::getDescription()
{
	return _getDescription() + " is " + ((state == DEAD)? "dead.": "alive.");
}

bool Runner::initialize()
{
	if(isDead()) return false;

	return _init();
}

bool Runner::run()
{
	if(isDead()) return false;

	return _run();
}

bool Runner::finalize()
{
	if(isDead()) return false;

	return _final();
}

}}