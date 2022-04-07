#pragma once

#include "uiviewbase.h"

class UiTopView : public UiViewBase
{
public:
  UiTopView(const UiViewParams& p_Params);

  virtual void Draw();
};
