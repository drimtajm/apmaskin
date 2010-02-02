#ifndef LOGFRAMEWORK_H_
#define LOGFRAMEWORK_H_

/*
 * Borrowed from Dr dobbs Journal
 * http://www.ddj.com/cpp/201804215
 */
#include <sstream>
#include <string>
#include <stdio.h>
#include <sys/time.h>

namespace log {

inline std::string NowTime();

enum TLogLevel {ERROR, WARNING, INFO, DEBUG, DEBUG1, DEBUG2, DEBUG3, DEBUG4};

#ifndef LOG_MAX_LEVEL
#define LOG_MAX_LEVEL log::DEBUG4
#endif

template <typename T>
class Log
{
 public:
  Log() {}
  virtual ~Log();
  std::ostringstream& Get(TLogLevel level = INFO);
 public:
  static TLogLevel& ReportingLevel();
  static std::string ToString(TLogLevel level);
  static TLogLevel FromString(const std::string& level);
 protected:
  std::ostringstream os;
 private:
  Log(const Log&);
  Log& operator =(const Log&);
};

template <typename T>
std::ostringstream& Log<T>::Get(TLogLevel level)
{
  os << NowTime();
  os << " " << ToString(level) << ": ";
  os << std::string(level > log::DEBUG ? level - log::DEBUG : 0, '\t');
  return os;
}

template <typename T>
Log<T>::~Log()
{
  os << std::endl;
  T::Output(os.str());
}

template <typename T>
TLogLevel& Log<T>::ReportingLevel()
{
  static TLogLevel reportingLevel = log::DEBUG4;
  return reportingLevel;
}

template <typename T>
std::string Log<T>::ToString(TLogLevel level)
{
  static const char* const buffer[] = {"ERROR", "WARNING", "INFO", "DEBUG", "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4"};
  return buffer[level];
}

template <typename T>
TLogLevel Log<T>::FromString(const std::string& level)
{
  if (level == "DEBUG4")
    return log::DEBUG4;
  if (level == "DEBUG3")
    return log::DEBUG3;
  if (level == "DEBUG2")
    return log::DEBUG2;
  if (level == "DEBUG1")
    return log::DEBUG1;
  if (level == "DEBUG")
    return log::DEBUG;
  if (level == "INFO")
    return log::INFO;
  if (level == "WARNING")
    return log::WARNING;
  if (level == "ERROR")
    return log::ERROR;
  Log<T>().Get(log::WARNING) << "Unknown logging level '" << level << "'. Using INFO level as default.";
  return log::INFO;
}


inline std::string NowTime()
{
  char buffer[11];
  time_t t;
  time(&t);
  tm r = {0};
  strftime(buffer, sizeof(buffer), "%X", localtime_r(&t, &r));
  struct timeval tv;
  gettimeofday(&tv, 0);
  char result[100] = {0};
  sprintf(result, "%s.%03ld", buffer, (long)tv.tv_usec / 1000); 
  return result;
}

}
#endif //LOGFRAMEWORK_H_

