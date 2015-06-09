//
// RM.cpp for paranoidRM in /home/aracthor/programs/projects/paranoidRM
// 
// Made by Aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Jun  8 21:36:03 2015 Aracthor
// Last Update Tue Jun  9 13:08:36 2015 Aracthor
//

#include <iostream>

#include "BooleanOption.hh"
#include "RM.hh"

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

RM::RM() :
  ListShellCommand("Remove listed files."),
  mRecursive(false),
  mForce(false)
{
  this->initTrashPath();
  this->addOption(new BooleanOption('f', "force", mForce));
  this->addOption(new BooleanOption('r', "recursive", mRecursive));
}

RM::~RM()
{
}


int
RM::runForArgument(const char* arg)
{
  std::string	fileName(arg);
  std::string	destination;
  bool		isDirectory;

  // File does not exist
  if (access(arg, F_OK) != 0)
    {
      if (mForce)
	return 0;
      std::cerr << "Cannot remove `" << arg << "`: no such file or directory" << std::endl;
      return 1;
    }

  // File is a directory
  isDirectory = (access((fileName + '/').c_str(), F_OK) == 0);
  if (isDirectory && !mRecursive)
    {
      std::cerr << "Cannot remove `" << arg << "`: Is a directory" << std::endl;
      return 1;
    }

  this->locateDestination(fileName, destination);
  this->prepareDestination(destination);

  if (rename(fileName.c_str(), destination.c_str()))
    {
      std::cerr << "Cannot remove `" << arg << "`: " << strerror(errno) << std::endl;
      return 1;
    }

  return 0;
}


void
RM::initTrashPath()
{
  const char*	home = getenv("HOME");
  char		buffer[0x100];
  struct tm*	localTime;
  time_t	seconds;

  if (home == NULL)
    throw ArgumentException("Environnement variable HOME is not defined");

  seconds = time(NULL);
  if (seconds == -1)
    throw ArgumentException("Cannot get current time");

  localTime = localtime(&seconds);
  strftime(buffer, 0x100, "%d-%m-%y", localTime);

  mTrashPath = home;
  mTrashPath += '/';
  mTrashPath += TRASH_FOLDER;
  mTrashPath += '/';
  if (access(mTrashPath.c_str(), F_OK) != 0)
    {
      if (mkdir(mTrashPath.c_str(), 0755) != 0)
	throw ArgumentException("Cannot create trash folder: ", strerror(errno));
    }

  mTrashPath += buffer;
  mTrashPath += '/';

  if (access(mTrashPath.c_str(), F_OK) != 0)
    {
      if (mkdir(mTrashPath.c_str(), 0755) != 0)
	throw ArgumentException("Cannot create today's trash subfolder: ", strerror(errno));
    }
}

void
RM::locateDestination(const std::string& source, std::string& destination)
{
  ssize_t	index;
  std::string	fileName(source);

  index = fileName.size();
  while (index > 0 && index >= static_cast<ssize_t>(fileName.size()) - 1)
    {
      fileName = fileName.substr(0, index);
      index = fileName.rfind('/');
    }
  fileName = fileName.substr(index + 1, fileName.size() - index - 1);

  destination = mTrashPath + fileName;
}

void
RM::prepareDestination(std::string& destination)
{
  while (access(destination.c_str(), F_OK) == 0)
    destination += '_';
}
