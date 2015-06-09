//
// ArgumentException.hpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:05:29 2015 Aracthor
// Last Update Mon Jun  8 21:08:47 2015 Aracthor
//

template <typename T>
ArgumentException::ArgumentException(const char* message, T argument1) :
  mMessage(std::string(message) + argument1)
{
}

template <typename T, typename U>
ArgumentException::ArgumentException(const char* message, T argument1, U argument2) :
  mMessage(std::string(message) + argument1 + argument2)
{
}
