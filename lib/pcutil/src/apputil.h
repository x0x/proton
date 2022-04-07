#pragma once

#include <string>

class AppUtil
{
public:
  static std::string GetAppNameVersion();
  static std::string GetAppVersion();
  static void SetDeveloperMode(bool p_DeveloperMode);
  static bool GetDeveloperMode();

private:
  static bool m_DeveloperMode;
};
