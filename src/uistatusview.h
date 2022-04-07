#pragma once

#include "uiviewbase.h"

class UiStatusView : public UiViewBase
{
public:
  UiStatusView(const UiViewParams& p_Params);

  virtual void Draw();
};
