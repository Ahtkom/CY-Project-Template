#include <Generator.h>
#include <iostream>

Generator::Generator(const std::filesystem::path &path, Project *type)
    : path_(path)
    , project_type(type)
{
}

void Generator::createTemplate()
{
    auto current_path = std::filesystem::current_path();
    auto target_path = current_path / project_type->getName();

    if (std::filesystem::exists(target_path)) {
        std::filesystem::remove_all(target_path);
    } else {
        std::filesystem::create_directory(target_path);
    }

    std::filesystem::copy(path_, target_path,
                          std::filesystem::copy_options::recursive);
}