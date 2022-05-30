#pragma once

#include <memory>
#include "baseobject.hpp"
#include "imodelimpl.hpp"

class Model : public BaseObject
{
public:
    Model(std::shared_ptr<IModelImpl> modelImpl, size_t id, const std::string &name = "Model", const Matrix &matrix = Matrix::identity());

    virtual void accept(IVisitor &visitor) override;

    friend class RenderVisitor;

private:
    IModelImpl &getDetails();

    std::shared_ptr<IModelImpl> modelImpl;
};
