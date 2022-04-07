#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class Protocol;
class ServiceMessage;
class UiController;
class UiModel;

class Ui
{
public:
  Ui();
  virtual ~Ui();

  void Run();
  void AddProtocol(std::shared_ptr<Protocol> p_Protocol);
  std::unordered_map<std::string, std::shared_ptr<Protocol>>& GetProtocols();
  void MessageHandler(std::shared_ptr<ServiceMessage> p_ServiceMessage);

private:
  std::shared_ptr<UiModel> m_Model;
  std::shared_ptr<UiController> m_Controller;
};
