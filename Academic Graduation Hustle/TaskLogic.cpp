#include "TaskLogic.h"

Task::~Task()
{ }
TaskInvoker::~TaskInvoker()
{ }
TaskReciever::~TaskReciever()
{ }

void TaskInvoker::AssignTask(Task* _task)
{
	this->task = _task;
}
void TaskInvoker::InvokeTask()
{
	this->task->execute();
}