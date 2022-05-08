#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <protype/Project.h>

#include <string>
#include <filesystem>

class Generator
{
public:
    static std::filesystem::path root_path;

    Generator(const std::filesystem::path &target_path, Project *type);

    ~Generator() = default;

    void createTemplate();

private:
    Project *project_type;

    std::filesystem::path target_path_;
};

#endif // GENERATOR_H_