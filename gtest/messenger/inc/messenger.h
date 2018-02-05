#ifndef MESSENGER_H_
#define MESSENGER_H_

#include <string>

class Messenger
{
  public:
    virtual ~Messenger() {}
    virtual string getMessage() = 0;
};

#endif /
