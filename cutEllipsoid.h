#ifndef CUTELLIPSOID_H_INCLUDED
#define CUTELLIPSOID_H_INCLUDED

#include "Figurageometrica.h"
///Classe cutEllipsoid derivada da classe FiguraGeometrica.
///
///Uma esfera dever� ser especificada para remo��o conforme a posi��o do centro e seus raios em pixels.
class cutEllipsoid : public FiguraGeometrica{
    int xcenter_; int ycenter_; int zcenter_; int rx_; int ry_; int rz_;
public:
    cutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_);
    void draw(Sculptor &t);
    ~cutEllipsoid(){};
};


#endif // CUTELLIPSOID_H_INCLUDED
