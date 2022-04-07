#pragma once

#include <ncursesw/ncurses.h>

#include "uiviewbase.h"

class UiListView : public UiViewBase
{
public:
  UiListView(const UiViewParams& p_Params);
  virtual ~UiListView();

  virtual void Draw();

private:
  WINDOW* m_PaddedWin = nullptr;
  int m_PaddedH = 0;
  int m_PaddedW = 0;
};
