//
// HelpOption.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:38:38 2015 Aracthor
// Last Update Mon Jun  8 21:42:09 2015 Aracthor
//

#ifndef HELP_OPTION_HH_
# define HELP_OPTION_HH_

# include "OptionParser.hh"
# include "ShellCommand.hh"

class	HelpOption : public OptionParser
{
public:
  HelpOption(ShellCommand* command);
  ~HelpOption();

public:
  void	onRead();

private:
  ShellCommand*	mCommand;
};

#endif // !HELP_OPTION_HH_
