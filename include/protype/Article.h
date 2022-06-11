#ifndef PROTYPE_ARTICLE_H_
#define PROTYPE_ARTICLE_H_

#include "protype/Project.h"

#include <string>

class Article : public Project
{
public:
  Article()
      : Project("templates\\article\\") {
    setName("article");
  }

  ~Article() override = default;
};

#endif // PROTYPE_BEAMER_H_