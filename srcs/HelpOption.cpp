
#include "HelpOption.hh"

HelpOption::HelpOption(ShellCommand* command) :
  OptionParser('h', "help", false),
  mCommand(command)
{
}

HelpOption::~HelpOption()
{
}


void
HelpOption::onRead()
{
  mCommand->printUsage();
  mCommand->stop();
}
