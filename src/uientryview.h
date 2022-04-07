#pragma once

#include "uiviewbase.h"

class UiEntryView : public UiViewBase
{
public:
  UiEntryView(const UiViewParams& p_Params);

  virtual void Draw();

private:
  int m_CursX = 0;
  int m_CursY = 0;
};
