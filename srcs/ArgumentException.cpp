//
// ArgumentException.cpp for ArgumentException in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:01:03 2015 Aracthor
// Last Update Mon Jun  8 21:04:43 2015 Aracthor
//

#include "ArgumentException.hh"

ArgumentException::ArgumentException(const char* message) :
  mMessage(message)
{
}

ArgumentException::~ArgumentException() throw()
{
}


const char*
ArgumentException::what() const throw()
{
  return (mMessage.c_str());
}
