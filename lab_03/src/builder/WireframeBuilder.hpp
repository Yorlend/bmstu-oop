#pragma once

#include "BaseObjectBuilder.hpp"
#include "object/BaseObject.hpp"

class WireframeBuilder : public BaseObjectBuilder 
{
public:
    virtual void buildVerts(const Vector& vert) override;       
    virtual void buildEdges(const Edge& edge) override;

    std::shared_ptr<BaseObject> assemble() const;

private:
    std::vector<Vector> vertices;
    std::vector<Edge> edges;
};
