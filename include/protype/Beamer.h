#ifndef PROTYPE_BEAMER_H_
#define PROTYPE_BEAMER_H_

#include <protype/Project.h>
#include <string>

class Beamer : public Project
{
public:
    Beamer()
        : Project("templates\\beamer\\")
    {
        setName("beamer");
    }

    ~Beamer() override = default;
};

#endif // PROTYPE_BEAMER_H_