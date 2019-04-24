#include "CommandQueue.h"

void CommandQueue::push(const Command& cmd)
{
	mCommandQueue.push(cmd);
}

Command CommandQueue::pop()
{
	mCommandQueue.pop();
}

bool CommandQueue::isEmpty()
{
	return mCommandQueue.empty();
}
