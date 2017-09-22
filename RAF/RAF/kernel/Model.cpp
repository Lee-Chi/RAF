#include "Model.h"

namespace raf{ namespace kernel{

Model::Model()
{
}

Model::~Model()
{
}

void Model::setValue(int key, int value)
{
	model[key] = value;
}

int Model::getValue(int key)
{
	return (model.find(key) != model.end())? model[key]: 0;
}

}}