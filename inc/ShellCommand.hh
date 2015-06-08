//
// ShellCommand.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 19:37:38 2015 Aracthor
// Last Update Mon Jun  8 21:43:31 2015 Aracthor
//

#ifndef SHELL_COMMAND_HH_
# define SHELL_COMMAND_HH_

# include <vector>

# include "ArgumentException.hh"
# include "OptionParser.hh"

class	ShellCommand
{
private:
  typedef std::vector<OptionParser*>	Options;

public:
  template <class T>
  static int	main(int argc, const char** argv);


public:
  ShellCommand(const char* usage);
  virtual ~ShellCommand();

public:
  void		parseArgs(int argc, const char** argv);
  virtual void	run();
  void		printUsage() const throw();
  void		stop();
  inline bool	isRunning() const;

protected:
  void		addOption(OptionParser* option);
  virtual void	onUnrequestedArg(const char* arg);

private:
  void		parseLongOption(const char* name);
  void		parseShortOption(char flag, bool canWaitForArg);
  void		parseFlags(const char* flags);
  void		parseArg(const char* arg);

private:
  Options		mOptions;
  OptionParser*		mArgWaiter;
  const char*		mBinaryName;
  const char* const	mUsage;
  bool			mRunning;
};

# include "ShellCommand.hpp"

#endif // !SHELL_COMMAND_HH_
