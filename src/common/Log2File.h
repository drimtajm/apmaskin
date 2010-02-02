#ifndef FILE2LOG_H_
#define FILE2LOG_H_

#include "LogFramework.h"
#include <stdlib.h>
#include <unistd.h>

namespace log {

class Output2FILE
{
 public:
  static FILE*& Stream() {
    static FILE* pStream = stderr;
    return pStream;
  }

  static void Output(const std::string& msg) {   
    FILE* pStream = Stream();
    if (!pStream)
      return;
    fprintf(pStream, "%s", msg.c_str());
    fflush(pStream);
  }
  static void Init(const std::string& fileName) {
    FILE* pStream = fopen(fileName.c_str(), "w");
    if (pStream) {
      Stream() = pStream;
    } else {
      static const size_t MAX_PATH = 260;
      char cwd[MAX_PATH];
      getcwd(cwd, MAX_PATH);
      Log<Output2FILE>().Get(log::ERROR) << "Could not open \"" << cwd << "/" << fileName << "\" for writing. Sending logs to stderr instead.";
    }
  }
  static void Close() {
    if (Stream() != stderr)
      fclose(Stream());
  }
};

class FILELog : public Log<Output2FILE> {}; // same as typedef Log<Output2STDERR> FILELog;

#define LOG(level) \
  if (level > LOG_MAX_LEVEL) ;					\
  else if (level > log::FILELog::ReportingLevel() || !log::Output2FILE::Stream()) ; \
  else log::FILELog().Get(level)

}
#endif
