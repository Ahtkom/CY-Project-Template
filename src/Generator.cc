#include "Generator.h"

#include "config.h"
#include "protype/Article.h"
#include "protype/Program.h"
#include "protype/Project.h"
#include "protype/Report.h"

#include <filesystem>
#include <ios>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ccyy {
namespace gen {

Generator::Generator(Path target_path, Project *project, std::string openmode)
    : target_root_(target_path)
    , project_(project)
    , openmode_(openmode) { }

void Generator::generate() const {
    namespace fs = std::filesystem;

    auto templatePath = cygen_config::ROOT_PATH / project_->getTemplateName();
    if (!fs::exists(templatePath)) {
        throw std::runtime_error("Template does not exist at \"" + templatePath.string() + "\"!");
    }

    if (fs::exists(target_root_)) {
        if (openmode_ == "overwrite") {
            fs::remove_all(target_root_);
        }
    }
    fs::create_directory(target_root_);
    if (project_->getName() == "project") {
        fs::copy(templatePath, target_root_, fs::copy_options::recursive);
    } else {
        Path targetDir = target_root_ / project_->getName();
        Path target    = targetDir / project_->getTypeName();
        fs::create_directory(targetDir);
        fs::create_directory(target);
        fs::copy(templatePath, target, fs::copy_options::recursive);
    }
}

} // namespace gen
} // namespace ccyy