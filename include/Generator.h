#pragma once

#include "protype/Project.h"

#include <boost/program_options.hpp>
#include <filesystem>
#include <string>

namespace ccyy {
namespace gen {

/**
 * @brief project template generator, it will generate target type project
 *        under \c target_root
 */
class Generator
{
    using Path = std::filesystem::path;

public:
    Generator(Path target_root, Project *project, std::string openmode);

    ~Generator() = default;

    void generate() const;

private:
    Path target_root_;

    Project *project_;
    
    std::string openmode_;
};

} // namespace gen
} // namespace ccyy