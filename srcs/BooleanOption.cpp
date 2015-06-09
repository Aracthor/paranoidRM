//
// BooleanOption.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Jun  9 12:39:43 2015 Aracthor
// Last Update Tue Jun  9 12:41:41 2015 Aracthor
//

#include "BooleanOption.hh"

BooleanOption::BooleanOption(char flag, const char* name, bool& data) :
  OptionParser(flag, name, false),
  mData(data)
{
}

BooleanOption::~BooleanOption()
{
}


void
BooleanOption::onRead()
{
  mData = true;
}
