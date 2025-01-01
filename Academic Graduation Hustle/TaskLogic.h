#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

/// <summary>
/// Abstrakcyjna klasa polecenia.
/// </summary>
class Task
{
public:

	virtual ~Task() = 0;

private:


};
/// <summary>
/// Abstrakcyjna klasa wywo³uj¹ca zadania.
/// </summary>
class TaskInvoker
{
public:

	virtual ~TaskInvoker() = 0;

private:


};
/// <summary>
/// Abstrakcyjna klasa otrzymuj¹ca polecenia.
/// </summary>
class TaskReciever
{
public:

	virtual ~TaskReciever() = 0;

private:


};