#pragma once

#include "protype/Project.h"

#include <string>

namespace ccyy {
namespace gen {

class Article : public Project
{
public:
    Article(std::string project_name)
        : Project("templates/project/article/", project_name) { }

    ~Article() override = default;

    std::string getTypeName() override { return "article"; }
};

} // namespace gen
} // namespace ccyy
