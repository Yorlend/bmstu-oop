#pragma once

class SceneManager
{
public:
    void createNewScene();
    void renderScene();

private:
    std::shared_ptr<Scene> scene;
};
