#pragma once

#include <string>
#include <vector>

#include "uidialog.h"

class UiListDialog : public UiDialog
{
public:
  UiListDialog(const UiDialogParams& p_Params);
  virtual ~UiListDialog();

  bool Run();
  void KeyHandler(wint_t p_Key);

protected:
  virtual void OnSelect() = 0;
  virtual void OnBack() = 0;
  virtual bool OnTimer() = 0;
  virtual void UpdateList() = 0;

private:
  void Draw();

protected:
  bool m_Running = true;
  bool m_Result = false;
  std::wstring m_FilterStr;
  std::vector<std::wstring> m_Items;
  int m_Index = 0;
  int m_MaxW = 0;
};
