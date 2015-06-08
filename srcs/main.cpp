//
// main.cpp for korean_teacher in /home/aracthor/programs/projects/korean_teacher
// 
// Made by aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Mar  2 15:48:36 2015 aracthor
// Last Update Mon Mar  2 15:50:06 2015 aracthor
//

#include <exception>
#include <iostream>

int	main()
{
  int	returnValue;

  try
    {
      // TODO
      returnValue = 0;
    }
  catch (const std::exception& exception)
    {
      std::cerr << "FATAL ERROR: " << exception.what() << std::endl;
      returnValue = 1;
    }

  return (returnValue);
}
