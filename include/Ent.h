#pragma once

#include "Math/CoordTL.h"

class Ent {
protected:
    Math::CoordF position;
    Math::CoordF size;

public:
    Ent(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f));

    virtual ~Ent();

    void setPosition(Math::CoordF pos);

    Math::CoordF getPosition() const;

    void setSize(Math::CoordF size);

    Math::CoordF getSize() const;

    virtual void render() = 0;

    virtual void update(const float dt) = 0;

    virtual void initialize() = 0;
};
