#pragma once
#include "Command.h"
#include <queue>
class CommandQueue
{
public:
	void push(const Command& cmd);
	Command pop();
	bool isEmpty();
private:
	std::queue<Command> mQueue;

};

