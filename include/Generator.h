#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <protype/Project.h>
#include <Option.h>

#include <string>
#include <filesystem>

/**
 * @brief project template generator, it will generate target type project
 *        under \c target_path
 */
class Generator
{
public:
    // the project path on your device, you need to redeclare it in main.cpp
    static std::filesystem::path root_path;

    Generator(const std::filesystem::path &target_path,
              Project *type,
              Option opt = Option::overwrite);

    ~Generator() = default;

    void createTemplate();

private:
    std::filesystem::path target_path_;

    Project *project_type;

    Option opt_;
};

#endif // GENERATOR_H_