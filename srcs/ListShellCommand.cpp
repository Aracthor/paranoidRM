//
// ListShellCommand.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:12:04 2015 Aracthor
// Last Update Mon Jun  8 21:16:56 2015 Aracthor
//

#include "ListShellCommand.hh"

ListShellCommand::ListShellCommand(const char* usage) :
  ShellCommand(usage)
{
}

ListShellCommand::~ListShellCommand()
{
}


void
ListShellCommand::run()
{
  for (Arguments::iterator it = mArguments.begin(); it != mArguments.end(); ++it)
    this->runForArgument(*it);
}


void
ListShellCommand::onUnrequestedArg(const char* arg)
{
  mArguments.push_back(arg);
}
