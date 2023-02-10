#pragma once

#include "protype/Project.h"

#include <string>

namespace ccyy {
namespace gen {

class Program : public Project
{
public:
    Program(std::string project_name)
        : Project("templates/project/program/", project_name) { }

    ~Program() override = default;

    std::string getTypeName() override { return "program"; }
};

} // namespace gen
} // namespace ccyy