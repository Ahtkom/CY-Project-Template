#include <iostream>
#include <memory>
#include <Generator.h>
#include <protype/Report.h>
#include <protype/Beamer.h>
#include <filesystem>

using std::filesystem::path;

int main(int, char** args) {
    // set your root_path here
    path root_path = "D:\\pmk\\project\\cy-project-template";

    // project type from user input
    std::string project_type = *(args + 1);

    std::unique_ptr<Project> project;
    if (project_type == "report") {
        project = std::make_unique<Report>();
    } else if (project_type == "beamer") {
        project = std::make_unique<Beamer>();
    } else {
        throw std::runtime_error("Invalid project type: " + project_type);
    }

    Generator generator(root_path / project->getTemplatePath(), project.get());

    generator.createTemplate();
}
