#ifndef PROTYPE_PROGRAM_H_
#define PROTYPE_PROGRAM_H_

#include "protype/Project.h"

#include <string>

class Program : public Project
{
public:
  Program()
      : Project("templates\\program\\") {
    setName("program");
  }

  ~Program() override = default;
};

#endif // PROTYPE_PROGRAM_H_