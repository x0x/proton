#include "uiscreen.h"

#include <ncursesw/ncurses.h>

UiScreen::UiScreen()
{
  wclear(stdscr);
  wrefresh(stdscr);
  getmaxyx(stdscr, m_H, m_W);
}

int UiScreen::W()
{
  return m_W;
}

int UiScreen::H()
{
  return m_H;
}
