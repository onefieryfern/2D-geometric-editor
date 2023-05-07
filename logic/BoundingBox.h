#ifndef INC_2D_GEOMETRIC_EDITOR_BOUNDINGBOX_H
#define INC_2D_GEOMETRIC_EDITOR_BOUNDINGBOX_H

#include "geometry_structs.h"

class BoundingBox {
private:
    Position m_topLeft {};
    Position m_bottomRight {};

public:
    BoundingBox () = default;
    BoundingBox (const Position& topLeft, const Position& bottomRight);

    bool encasesPosition (const Position& position) const;

    void draw () const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_BOUNDINGBOX_H
