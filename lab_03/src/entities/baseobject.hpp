#pragma once

#include <list>
#include <string>
#include <memory>
#include "math/transform.hpp"

class IVisitor;

class BaseObject
{
public:
    using Iterator = std::list<std::shared_ptr<BaseObject>>::iterator;
    using ConstIterator = std::list<std::shared_ptr<BaseObject>>::const_iterator;

    BaseObject(size_t id, const std::string &name = "BaseObject", const Matrix &matrix = Matrix::identity());
    virtual ~BaseObject() = default;

    size_t getId() const;

    const std::string &getName() const;
    void setName(const std::string &newName);

    const Matrix &getMatrix() const;
    void setMatrix(const Matrix &newMatrix);

    bool getVisibility() const;
    void setVisibility(bool visibility);

    virtual bool isComposite() const;

    virtual bool insertChild(Iterator pos, std::shared_ptr<BaseObject> obj);
    virtual bool removeChild(Iterator pos);

    virtual Iterator begin();
    virtual Iterator end();

    virtual void accept(IVisitor &visitor) = 0;

private:
    size_t id;
    std::string name;
    Matrix matrix;
    bool visible;
};
