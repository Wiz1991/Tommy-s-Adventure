#include "CommandQueue.h"

void CommandQueue::push(const Command& cmd)
{
	mQueue.push(cmd);
}

Command CommandQueue::pop()
{
	Command cmd = mQueue.front();
	mQueue.pop();
	return cmd;
}

bool CommandQueue::isEmpty()
{
	return mQueue.empty();
}
