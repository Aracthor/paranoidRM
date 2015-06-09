//
// ListShellCommand.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:12:00 2015 Aracthor
// Last Update Tue Jun  9 11:31:56 2015 Aracthor
//

#ifndef LIST_SHELL_COMMAND_HH_
# define LIST_SHELL_COMMAND_HH_

# include <vector>

# include "ShellCommand.hh"

class	ListShellCommand : public ShellCommand
{
private:
  typedef std::vector<const char*>	Arguments;

public:
  ListShellCommand(const char* usage);
  virtual ~ListShellCommand();

public:
  int	run();

protected:
  void		onUnrequestedArg(const char* arg);
  virtual int	runForArgument(const char* arg) = 0;

private:
  Arguments	mArguments;
};

#endif // !LIST_SHELL_COMMAND_HH_
