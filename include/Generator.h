#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <protype/Project.h>

#include <string>
#include <filesystem>

class Generator
{
public:
    Generator(const std::filesystem::path &path, Project *type);

    ~Generator() = default;

    void createTemplate();

private:
    Project *project_type;

    std::filesystem::path path_;
};

#endif // GENERATOR_H_