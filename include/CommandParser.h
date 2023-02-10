#pragma once

#include "protype/Article.h"
#include "protype/Program.h"
#include "protype/Project.h"
#include "protype/Report.h"

#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <filesystem>
#include <memory>
#include <stdexcept>
#include <string>

namespace ccyy {
namespace gen {

class CommandParser
{
public:
    CommandParser(int argc, char **argv)
        : update_(*(argv + 1) == std::string("update")) {
        namespace po = boost::program_options;

        po::options_description desc("Allowed options");
        desc.add_options()("help,h", "produce help message")(TYPE_OPTION, po::value<std::string>(), "project type")(
            NAME_OPTION, po::value<std::string>(), "project name")(OPEN_OPTION, po::value<std::string>(), "open mode")(
            TEMPLATE_PATH, po::value<std::string>(), "template path to copy when updating");

        po::store(po::parse_command_line(argc, argv, desc), vm_);
        po::notify(vm_);
    }

    bool isToUpdate() const { return update_; }

    bool isToGenerate() const { return !isToUpdate(); }

    std::unique_ptr<Project> getType() const {
        if (!vm_.contains("type"))
            throw std::runtime_error("Project type unset!");

        std::string type = vm_.at("type").as<std::string>();
        std::string name = getName();
        std::unique_ptr<Project> project;
        if (type == "project") {
            project.reset(new Project(name));
        } else if (type == "program") {
            project.reset(new Program(name));
        } else if (type == "report") {
            project.reset(new Report(name));
        } else if (type == "article") {
            project.reset(new Article(name));
        } else {
            throw std::runtime_error("Unknown project type \"" + type + "\"");
        }
        return project;
    }

    std::string getName() const {
        if (!vm_.contains("name"))
            throw std::runtime_error("Project name unset!");
        return vm_.at("name").as<std::string>();
    }

    std::string getOpenmode() const {
        if (!vm_.contains("openmode"))
            return "overwrite";
        return vm_.at("openmode").as<std::string>();
    }

    std::filesystem::path getNewTemplate() const {
        if (!vm_.contains("template-path"))
            throw std::runtime_error("New template path unset!");
        return vm_.at("template-path").as<std::string>();
    }

private:
    static constexpr const char *TYPE_OPTION   = "type,t";
    static constexpr const char *NAME_OPTION   = "name,n";
    static constexpr const char *OPEN_OPTION   = "openmode,o";
    static constexpr const char *TEMPLATE_PATH = "template-path,p";

    bool update_;

    boost::program_options::variables_map vm_;
};

} // namespace gen
} // namespace ccyy