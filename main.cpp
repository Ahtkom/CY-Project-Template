#include "CommandParser.h"
#include "Generator.h"
#include "config.h"

#include <filesystem>
#include <iostream>
#include <memory>

using namespace ccyy;
using namespace gen;

namespace fs = std::filesystem;

fs::path cygen_config::ROOT_PATH = "/home/ahtkom/pmk/project/CY-Project-Template/";

int main(int argc, char **argv) {
    if (cygen_config::ROOT_PATH.string() == "") {
        std::cerr << "Please set ROOT_PATH in main.cpp" << std::endl;
        return -1;
    }

    CommandParser parser(argc, argv);
    std::unique_ptr<Project> project = parser.getType();
    if (parser.isToGenerate()) {
        Generator(fs::current_path(), project.get(), parser.getOpenmode()).generate();
    } else {
    }
}
