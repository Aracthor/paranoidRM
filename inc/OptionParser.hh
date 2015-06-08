//
// OptionParser.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 20:03:35 2015 Aracthor
// Last Update Mon Jun  8 21:40:58 2015 Aracthor
//

#ifndef OPTION_PARSER_HH_
# define OPTION_PARSER_HH_

class	OptionParser
{
public:
  OptionParser(char flag, const char* name, bool needArg);
  virtual ~OptionParser();

public:
  virtual void onRead();
  virtual void parseArg(const char* arg);

public:
  inline char		getFlag() const;
  inline const char*	getName() const;
  inline bool		needArg() const;

protected:
  const char		mFlag;
  const	char* const	mName;
  const bool		mNeedArg;
};

# include "OptionParser.hpp"

#endif // !OPTION_PARSER_HH_
