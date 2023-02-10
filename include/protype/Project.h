#pragma once

#include <string>

namespace ccyy {
namespace gen {

enum ProjectType
{
    PROJECT,
    ARTICLE,
    PROGRAM,
    REPORT
};

class Project
{
public:
    Project(std::string template_name, std::string project_name)
        : template_name_(template_name)
        , project_name_(project_name) { }

    explicit Project(std::string project_name)
        : Project("templates/project/", project_name) { }

    virtual ~Project() = default;

    std::string getTemplateName() { return template_name_; }

    virtual std::string getTypeName() { return "project"; }

    std::string getName() { return project_name_; }

private:
    std::string template_name_; // relative

    std::string project_name_;
};

} // namespace gen
} // namespace ccyy