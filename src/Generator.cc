#include <Generator.h>
#include <iostream>

Generator::Generator
  (const std::filesystem::path &path, Project *type, Option opt)
    : target_path_(path / type->getName())
    , project_type(type)
    , opt_(opt)
{
}

void Generator::createTemplate()
{
    if (std::filesystem::exists(target_path_)) {
        std::filesystem::remove_all(target_path_);
    } else {
        std::filesystem::create_directory(target_path_);
    }

    std::filesystem::copy(root_path / "templates" / project_type->getName(),
                          target_path_, 
                          std::filesystem::copy_options::recursive);
}