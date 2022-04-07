#include "apputil.h"

bool AppUtil::m_DeveloperMode = false;

std::string AppUtil::GetAppNameVersion()
{
  static std::string nameVersion = "proton v" + GetAppVersion();
  return nameVersion;
}

std::string AppUtil::GetAppVersion()
{
#ifdef PROTON_PROJECT_VERSION
  static std::string version = "PROTON_PROJECT_VERSION";
#else
  static std::string version = "0.00";
#endif
  return version;
}

void AppUtil::SetDeveloperMode(bool p_DeveloperMode)
{
  m_DeveloperMode = p_DeveloperMode;
}

bool AppUtil::GetDeveloperMode()
{
  return m_DeveloperMode;
}
