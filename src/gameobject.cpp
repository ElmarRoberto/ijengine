#include "gameobject.h"

namespace ijengine {

    GameObject::GameObject(GameObject *parent, double xpos, double ypos)
        : m_parent(parent), m_x(xpos), m_y(ypos)
    {
    }

    GameObject::~GameObject()
    {
        for (auto obj : m_children)
            delete obj;
    }

    void
    GameObject::add_children(GameObject *obj)
    {
        if (obj != this)
            m_children.push_back(obj);
    }

    void
    GameObject::remove_children(GameObject *obj)
    {
        m_children.remove(obj);
    }

    double
    GameObject::x() const
    {
        return m_x + (m_parent ? m_parent->x() : 0);
    }

    double
    GameObject::y() const
    {
        return m_y + (m_parent ? m_parent->y() : 0);
    }

    void
    GameObject::update(unsigned now, unsigned last)
    {
        for (auto child : m_children)
            child->update(now, last);

        update_self(now, last);
    }

    void
    GameObject::draw(Canvas *canvas, unsigned now, unsigned last)
    {
        draw_self(canvas, now, last);

        for (auto child : m_children)
            child->draw(canvas, now, last);
    }
} 
