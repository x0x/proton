#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "protocol.h"
#include "uilistdialog.h"

class UiContactListDialog : public UiListDialog
{
public:
  UiContactListDialog(const UiDialogParams& p_Params);
  virtual ~UiContactListDialog();

  std::pair<std::string, ContactInfo> GetSelectedContact();

protected:
  virtual void OnSelect();
  virtual void OnBack();
  virtual bool OnTimer();

  void UpdateList();

private:
  std::unordered_map<std::string, std::unordered_map<std::string, ContactInfo>> m_DialogContactInfos;
  int64_t m_DialogContactInfosUpdateTime = 0;
  std::vector<std::pair<std::string, ContactInfo>> m_ContactInfosVec;
  std::pair<std::string, ContactInfo> m_SelectedContact;
};
