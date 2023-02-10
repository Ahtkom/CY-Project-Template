#pragma once

#include "protype/Project.h"

#include <string>

namespace ccyy {
namespace gen {

class Report : public Project
{
public:
    Report(std::string project_name)
        : Project("templates/project/report/", project_name) { }

    ~Report() override = default;

    std::string getTypeName() override { return "report"; }
};

} // namespace gen
} // namespace ccyy