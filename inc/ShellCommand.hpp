//
// ShellCommand.hpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 19:48:00 2015 Aracthor
// Last Update Mon Jun  8 21:55:41 2015 Aracthor
//

#include <exception>
#include <iostream>

template <class T>
int
ShellCommand::main(int argc, const char** argv)
{
  int		returnValue;

  try
    {
      T	command;

      returnValue = 1;
      try
	{
	  command.parseArgs(argc, argv);
	  returnValue = 0;
	}
      catch (const ArgumentException& exception)
	{
	  std::cerr << exception.what() << std::endl;
	  command.printUsage();
	}
      if (returnValue == 0 && command.isRunning())
	command.run();
    }
  catch (const std::exception& exception)
    {
      std::cerr << "FATAL ERROR: " << exception.what() << std::endl;
      returnValue = 2;
    }

  return (returnValue);
}

bool
ShellCommand::isRunning() const
{
  return (mRunning);
}
