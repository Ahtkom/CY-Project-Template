#pragma once

#include <filesystem>

namespace ccyy {
namespace gen {

struct cygen_config
{
    // the project path on your device, you need to redeclare it in main.cpp
    static std::filesystem::path ROOT_PATH;
};

} // namespace gen
} // namespace ccyy