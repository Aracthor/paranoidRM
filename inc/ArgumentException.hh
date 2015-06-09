//
// ArgumentException.hh for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:00:10 2015 Aracthor
// Last Update Mon Jun  8 21:09:03 2015 Aracthor
//

#ifndef ARGUMENT_EXCEPTION_HH_
# define ARGUMENT_EXCEPTION_HH_

# include <exception>
# include <string>

class	ArgumentException : public std::exception
{
public:
  ArgumentException(const char* message);
  template <typename T>
  ArgumentException(const char* message, T argument);
  template <typename T, typename U>
  ArgumentException(const char* message, T argument1, U argument2);
  ~ArgumentException() throw();

public:
  const char*	what() const throw();

private:
  const std::string	mMessage;
};

# include "ArgumentException.hpp"

#endif // !ARGUMENT_EXCEPTION_HH_
