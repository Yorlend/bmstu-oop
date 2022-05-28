#pragma once

#include <list>
#include <memory>

class BaseObject
{
public:
    using Iterator = std::list<std::shared_ptr<BaseObject>>::iterator;

    virtual ~BaseObject() = default;

    BaseObject() : visible(true), focus(false) {}

    virtual bool add(std::shared_ptr<BaseObject> obj) { return false; }
    virtual bool remove(Iterator iter) { return false; }
    virtual Iterator begin() { return Iterator(); }
    virtual Iterator end() { return Iterator(); }

    virtual bool isComposite() const { return false; }

    bool getVisibility() const { return visible; }
    void setVisibility(bool visibility) { visible = visibility; }

    bool getFocus() const { return focus; }
    void setFocus(bool focused) { focus = focused; }
private:
    bool visible;
    bool focus;
};
