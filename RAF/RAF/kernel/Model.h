#pragma once

#include <map>
	using std::map;
	using std::pair;

namespace raf{ namespace kernel{

class Model
{
public:
	Model();
	~Model();

	void setValue(int key,int value);
	int getValue(int key);

private:
	map<int, int> model;
};

}}