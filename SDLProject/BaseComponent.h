#pragma once
#include <string>

class BaseComponent
{
public:
	virtual std::string getComponentType() = 0;
};