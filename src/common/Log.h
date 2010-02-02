#ifndef LOG_H
#define LOG_H
#include "LogFramework.h"

/*
 * The output policy class must implement the following interface:
class Output2XXXX
{
 public:
  static FILE*& Stream();
  static void Output(const std::string& msg) 
};

 */
#include "Log2File.h"

#endif
