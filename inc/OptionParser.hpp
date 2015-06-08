//
// OptionParser.hpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 20:05:10 2015 Aracthor
// Last Update Mon Jun  8 20:10:50 2015 Aracthor
//

char
OptionParser::getFlag() const
{
  return (mFlag);
}

const char*
OptionParser::getName() const
{
  return (mName);
}

bool
OptionParser::needArg() const
{
  return (mNeedArg);
}
