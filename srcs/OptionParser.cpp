//
// OptionParser.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 20:03:27 2015 Aracthor
// Last Update Mon Jun  8 20:52:39 2015 Aracthor
//

#include "OptionParser.hh"

OptionParser::OptionParser(char flag, const char* name, bool needArg) :
  mFlag(flag),
  mName(name),
  mNeedArg(needArg)
{
}

OptionParser::~OptionParser()
{
}


void
OptionParser::onRead()
{
}

void
OptionParser::parseArg(const char* arg __attribute__ ((unused)))
{
}
