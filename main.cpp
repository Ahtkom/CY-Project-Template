#include <iostream>
#include <Generator.h>
#include <protype/Article.h>
#include <protype/Report.h>
#include <protype/Program.h>
#include <memory>
#include <filesystem>

using std::filesystem::create_directory;
using std::filesystem::path;

// set your root_path here (indicates to project/)
path Generator::root_path = "D:\\pmk\\project\\cy-project-template";


/**
 * @brief Create specific project with type @c project_type under @c dir_path
 * 
 * @param project_type optional for
 *     \li "project",
 *     \li "article",
 *     \li "program",
 *     \li "report".
 */
void generate_concrete(const std::string &project_type, path dir_path)
{
    std::unique_ptr<Project> project;
    
    if (project_type == "article") {
        project = std::make_unique<Article>();
    } else if (project_type == "program") {
        project = std::make_unique<Program>();
    } else if (project_type == "report") {
        project = std::make_unique<Report>();
    } else {
        throw std::runtime_error("Invalid project type: " + project_type);
    }

    Generator generator(dir_path, project.get());

    generator.createTemplate();
}

int main(int, char** args)
{
    // project type from user input
    std::string project_type = *(args + 1);

    path current_path = std::filesystem::current_path();

    std::unique_ptr<Project> project;

    if (project_type == "project") {
        create_directory(current_path / "doc");
        create_directory(current_path / "references");

        generate_concrete("article", current_path / "doc");
        generate_concrete("report", current_path / "doc");

        generate_concrete("program", current_path);
    } else {
        generate_concrete(project_type, current_path);
    }
}
