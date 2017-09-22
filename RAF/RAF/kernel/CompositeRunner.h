#pragma once

#include "Runner.h"

#include <vector>
	using std::vector;

namespace raf{ namespace kernel{

class CompositeRunner: public Runner
{
public:
	CompositeRunner();
	~CompositeRunner();

	void add(Runner*);
	int size() const;
	bool isEmpty() const;
	bool isContain() const;

	Runner* getRunner(int idx) const;
	vector<Runner*> getRunners() const;

protected:
	bool _init() override;
	bool _run() override;
	bool _final() override;

	string _getDescription() override;
	
private:
	void eraseDeadRunner();

private:
	vector<Runner*> runners;
};

}}