//
// RM.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:36:09 2015 Aracthor
// Last Update Mon Jun  8 21:36:31 2015 Aracthor
//

#ifndef RM_HH_
# define RM_HH_

# include "ListShellCommand.hh"

class	RM : public ListShellCommand
{
public:
  RM();
  ~RM();

protected:
  void	runForArgument(const char* arg);
};

#endif // !RM_HH_
