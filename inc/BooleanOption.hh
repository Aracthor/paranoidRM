//
// BooleanOption.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Jun  9 12:39:40 2015 Aracthor
// Last Update Tue Jun  9 12:41:49 2015 Aracthor
//

#ifndef BOOLEAN_OPTION_HH_
# define BOOLEAN_OPTION_HH_

# include "OptionParser.hh"

class	BooleanOption : public OptionParser
{
public:
  BooleanOption(char flag, const char* name, bool& data);
  ~BooleanOption();

public:
  void onRead();

private:
  bool&	mData;
};

#endif // !BOOLEAN_OPTION_HH_
