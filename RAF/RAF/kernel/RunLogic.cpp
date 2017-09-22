#include "RunLogic.h"

namespace raf{ namespace kernel{

RunLogic::RunLogic(): logic(new NullLogic())
{
}

RunLogic::~RunLogic()
{
	if(logic) delete logic;
}

void RunLogic::setLogic(Logic* l)
{
	if(logic)
	{
		delete logic;
		logic = NULL;
	}
	logic = l;
}

Logic* RunLogic::getLogic()
{
	return logic;
}

string RunLogic::getDescription()
{
	return "Logic = " + logic->getDescription();
}

bool RunLogic::doAction()
{
	return logic->execute();
}

}}