#include "objectmanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "io/filereader.hpp"
#include "builder/modelbuilder.hpp"
#include "builder/camerabuilder.hpp"
#include "directors/defaultcamdirector.hpp"
//#include "visitor/transformvisitor.hpp"

ObjectManager::ObjectManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY)),
      importDirector(solution.getObjectDirector(MODEL_DIRECTOR)),
      defaultCameraDirector(solution.getObjectDirector(DEFAULT_CAMERA_DIRECTOR))
{
}

void ObjectManager::importObject(const std::string &filename)
{
    FileReader reader(filename);
    ModelBuidler builder;

    importDirector->setReader(reader);
    importDirector->setBuilder(builder);

    auto object = importDirector->construct();
    auto &scene = dataRepository->getScene();
    scene.insertObject(scene.end(), std::move(object));
}

void ObjectManager::removeObject(size_t id)
{
    auto &scene = dataRepository->getScene();

    auto iter = scene.findObjectById(id);
    if (iter != scene.end())
        scene.removeObject(iter);
}

void ObjectManager::addCamera(const Vector &position, const Vector &eye)
{
    auto &scene = dataRepository->getScene();

    CameraBuilder builder;
    defaultCameraDirector->setBuilder(builder);

    std::shared_ptr<BaseObject> camera = defaultCameraDirector->construct();

    camera->setMatrix(Matrix::fpsModel(position, eye));

    scene.insertObject(scene.end(), camera);
}

void ObjectManager::transformObject(size_t id, const Matrix &transform)
{
    auto &scene = dataRepository->getScene();
    auto object = *scene.findObjectById(id);

    auto old_trans = object->getMatrix();

    auto new_trans = transform * old_trans;

    object->setMatrix(new_trans);
}
