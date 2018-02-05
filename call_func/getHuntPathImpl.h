#ifndef GET_HUNT_PATH_IMPL_H_
#define GET_HUNT_PATH_IMPL_H_

#include "getHuntPath.h"

class GetHuntPathImpl : public GetHuntPath
{
  public:
    GetHuntPathImpl();
    bool printHuntPath(std::string&) override;
};
#endif
