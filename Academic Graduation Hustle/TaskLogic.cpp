#include "TaskLogic.h"

TaskInvoker::~TaskInvoker()
{ }

void TaskInvoker::AssignTask(Task* _task)
{
	this->task = _task;
}
void TaskInvoker::InvokeTask()
{
	this->task->execute();
}