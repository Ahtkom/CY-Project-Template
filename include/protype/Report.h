#ifndef PROTYPE_REPORT_H_
#define PROTYPE_REPORT_H_

#include "protype/Project.h"

#include <string>

class Report : public Project
{
public:
  Report()
      : Project("templates\\report\\") {
    setName("report");
  }

  ~Report() override = default;
};

#endif // PROTYPE_REPORT_H_