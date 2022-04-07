#pragma once

#include <string>

#include "config.h"

class UiConfig
{
public:
  static void Init();
  static void Cleanup();
  static bool GetBool(const std::string& p_Param);
  static void SetBool(const std::string& p_Param, const bool& p_Value);

private:
  static Config m_Config;
};
