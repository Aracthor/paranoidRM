//
// ShellCommand.hpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 19:48:00 2015 Aracthor
// Last Update Tue Jun  9 13:19:49 2015 Aracthor
//

#include <exception>
#include <iostream>

template <class T>
int
ShellCommand::main(int argc, const char** argv)
{
  int		returnValue = 0;

  try
    {
      T	command;

      command.parseArgs(argc, argv);
      if (command.isRunning())
	returnValue = command.run();
    }
  catch (const ArgumentException& exception)
    {
      std::cerr << argv[0] << ": " << exception.what() << std::endl;
      std::cerr << "Try '" << argv[0] << " --help' for more information." << std::endl;
      returnValue = 2;
    }
  catch (const std::exception& exception)
    {
      std::cerr << "FATAL ERROR: " << exception.what() << std::endl;
      returnValue = 3;
    }

  return (returnValue);
}

bool
ShellCommand::isRunning() const
{
  return (mRunning);
}

const char*
ShellCommand::getBinaryName() const
{
  return (mBinaryName);
}

const char*
ShellCommand::getUsage() const
{
  return (mUsage);
}
