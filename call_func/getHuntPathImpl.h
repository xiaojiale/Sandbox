#ifndef GET_HUNT_PATH_IMPL_H_
#define GET_HUNT_PATH_IMPL_H_

#include "getHuntPath.h"
#include <string>

class GetHuntPathImpl : public GetHuntPath
{
  public:
    GetHuntPathImpl();
    std::string printHuntPath() override;
};
#endif
