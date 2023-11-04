#pragma once

#include"Scene.h"

class Title : public Scene 
{
private:
    int Title_Image;
    int Title_BGM;
    int Title_SE;

public:
    Title();
    ~Title();

    void Update() override;
    void Draw() override;
};
