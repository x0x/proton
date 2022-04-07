#pragma once

#include <cstdint>
#include <string>

class TimeUtil
{
public:
  static int64_t GetCurrentTimeMSec();
  static std::string GetTimeString(int64_t p_TimeSent, bool p_ShortToday);
  static void Sleep(double p_Sec);
};
