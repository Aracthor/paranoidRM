//
// RM.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:36:09 2015 Aracthor
// Last Update Tue Jun  9 13:06:17 2015 Aracthor
//

#ifndef RM_HH_
# define RM_HH_

# include "ListShellCommand.hh"

# define TRASH_FOLDER	".trash"

class	RM : public ListShellCommand
{
public:
  RM();
  ~RM();

protected:
  int	runForArgument(const char* arg);

private:
  void	initTrashPath();
  void	locateDestination(const std::string& source, std::string& destination);
  void	prepareDestination(std::string& destination);

private:
  std::string	mTrashPath;
  bool		mRecursive;
  bool		mForce;
};

#endif // !RM_HH_
