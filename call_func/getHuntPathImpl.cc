#include "getHuntPathImpl.h"

GetHuntPathImpl::GetHuntPathImpl(){}
bool GetHuntPathImpl::printHuntPath(std::string& m_huntPath)
{
  m_huntPath = "BXP_01";
  std::cout << "HuntPath is " << m_huntPath << std::endl;
  return true;
}
