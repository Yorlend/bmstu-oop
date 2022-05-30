#include "model.hpp"
#include "visitor/ivisitor.hpp"

Model::Model(std::shared_ptr<IModelImpl> modelImpl, size_t id, const std::string &name, const Matrix &matrix)
    : BaseObject(id, name, matrix), modelImpl(std::move(modelImpl))
{
}

void Model::accept(IVisitor &visitor)
{
    visitor.visit(*this);
}

IModelImpl &Model::getDetails()
{
    return *modelImpl.get();
}
