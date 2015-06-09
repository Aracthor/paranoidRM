//
// ListShellCommand.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:12:04 2015 Aracthor
// Last Update Tue Jun  9 13:18:58 2015 Aracthor
//

#include <algorithm>

#include "ArgumentException.hh"
#include "ListShellCommand.hh"

ListShellCommand::ListShellCommand(const char* usage) :
  ShellCommand(usage)
{
}

ListShellCommand::~ListShellCommand()
{
}


int
ListShellCommand::run()
{
  int	returnValue = 0;

  if (mArguments.size() == 0)
    throw ArgumentException("Missing operand");

  for (Arguments::iterator it = mArguments.begin(); it != mArguments.end(); ++it)
    returnValue = std::max(returnValue, this->runForArgument(*it));

  return (returnValue);
}


void
ListShellCommand::onUnrequestedArg(const char* arg)
{
  mArguments.push_back(arg);
}
