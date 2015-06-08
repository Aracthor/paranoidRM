//
// ShellCommand.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 19:37:35 2015 Aracthor
// Last Update Mon Jun  8 21:51:56 2015 Aracthor
//

#include <iostream>

#include "HelpOption.hh"
#include "ShellCommand.hh"

#include <cstring>

ShellCommand::ShellCommand(const char* usage) :
  mUsage(usage)
{
  this->addOption(new HelpOption(this));
}

ShellCommand::~ShellCommand()
{
  for (Options::iterator it = mOptions.begin(); it != mOptions.end(); ++it)
    delete *it;
}


void
ShellCommand::parseArgs(int argc, const char** argv)
{
  int	i;

  mBinaryName = argv[0];
  mArgWaiter = NULL;
  mRunning = true;

  for (i = 0; i < argc && mRunning; ++i)
    {
      this->parseArg(argv[i]);
    }
  if (mArgWaiter != NULL)
    throw ArgumentException("Missing argument for option ", mArgWaiter->getName());
}

void
ShellCommand::run()
{
}

void
ShellCommand::printUsage() const throw()
{
  std::cerr << "Usage: " << mBinaryName << ' ' << mUsage << std::endl << std::endl;
  for (Options::const_iterator it = mOptions.begin(); it != mOptions.end(); ++it)
    {
      std::cerr << '-' << (*it)->getFlag() << ": " << (*it)->getName() << std::endl;
    }
}

void
ShellCommand::stop()
{
  mRunning = false;
}


void
ShellCommand::addOption(OptionParser* option)
{
  mOptions.push_back(option);
}

void
ShellCommand::onUnrequestedArg(const char* arg)
{
  throw ArgumentException("Unexpected argument ", arg);
}


void
ShellCommand::parseLongOption(const char* name)
{
  OptionParser*	option = NULL;

  for (Options::iterator it = mOptions.begin(); it != mOptions.end(); ++it)
    {
      if (!strcmp((*it)->getName(), name))
	{
	  option = *it;
	  break;
	}
    }

  if (option == NULL)
    throw ArgumentException("Unknow option ", name);

  option->onRead();
  if (option->needArg())
    mArgWaiter = option;
}

void
ShellCommand::parseShortOption(char flag, bool canWaitForArg)
{
  OptionParser*	option = NULL;

  for (Options::iterator it = mOptions.begin(); it != mOptions.end(); ++it)
    {
      if ((*it)->getFlag() == flag)
	{
	  option = *it;
	  break;
	}
    }

  if (option == NULL)
    throw ArgumentException("Unknow flag ", flag);

  if (option->needArg() && !canWaitForArg)
    throw ArgumentException("flag ", flag, " must be alone");

  option->onRead();
  if (option->needArg())
    mArgWaiter = option;
}

void
ShellCommand::parseFlags(const char* flags)
{
  if (flags[1] != '\0')
    {
      for (int i = 0; flags[i] != '\0'; ++i)
	this->parseShortOption(flags[i], false);
    }
  else
    {
      this->parseShortOption(flags[0], true);
    }
}

void
ShellCommand::parseArg(const char* arg)
{
  if (arg[0] == '-' && arg[1] == '-')
    {
      if (mArgWaiter != NULL)
	throw ArgumentException("Missing argument for option ", mArgWaiter->getName());
      this->parseLongOption(&arg[2]);
    }
  else if (arg[0] == '-')
    {
      if (mArgWaiter != NULL)
	throw ArgumentException("Missing argument for option ", mArgWaiter->getName());
      this->parseFlags(&arg[1]);
    }
  else if (mArgWaiter != NULL)
    {
      mArgWaiter->parseArg(arg);
      mArgWaiter = NULL;
    }
  else
    {
      this->onUnrequestedArg(arg);
    }
}
