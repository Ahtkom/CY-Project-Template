#ifndef PROJECT_H_
#define PROJECT_H_

#include <string>

class Project
{
public:
  Project(std::string path)
      : template_path_(path) { }

  virtual ~Project() = default;

  std::string getTemplatePath() { return template_path_; }

  std::string getName() { return name_; }

  void setName(const std::string &name) { name_ = name; }

private:
  std::string template_path_; // relative

  std::string name_;
};

#endif // PROJECT_H_