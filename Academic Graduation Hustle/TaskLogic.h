#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

/// <summary>
/// Abstrakcyjna klasa polecenia wykonuj¹ca okreœlone czynnoœci.
/// </summary>
class Task
{
public:

	virtual ~Task() = 0;

private:

	/// <summary>
	/// Wykonuje polecenie.
	/// </summary>
	virtual void execute() = 0;
};
/// <summary>
/// Abstrakcyjna klasa nadawana obiektom wywo³uj¹cym polecenia.
/// </summary>
class TaskInvoker
{
public:

	TaskInvoker()
		: task(nullptr)
	{ }
	virtual ~TaskInvoker() = 0;

	/// <summary>
	/// Przypisuje obiektowi konkretne polecenie.
	/// </summary>
	/// <param name="task">- typ polecenia</param>
	virtual void AssignTask(Task* task);
	/// <summary>
	/// Wywo³uje przypisane polecenie.
	/// </summary>
	virtual void InvokeTask();

private:

	Task* task;		// instancja wywo³ywanego polecenia
};
/// <summary>
/// Abstrakcyjna klasa otrzymuj¹ca polecenia.
/// </summary>
class TaskReciever
{
public:

	virtual ~TaskReciever() = 0;
};