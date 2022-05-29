#include "objectmanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "io/filereader.hpp"
#include "builder/modelbuilder.hpp"
//#include "visitor/transformvisitor.hpp"

ObjectManager::ObjectManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY)),
      importDirector(solution.getObjectDirector(MODEL_DIRECTOR))
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

void ObjectManager::transformObject(size_t id, const Transform &transform)
{
    auto &scene = dataRepository->getScene();

    ///TODO: do
    throw std::runtime_error("todo");
}
