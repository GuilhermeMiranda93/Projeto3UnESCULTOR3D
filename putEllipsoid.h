#ifndef PUTELLIPSOID_H_INCLUDED
#define PUTELLIPSOID_H_INCLUDED

#include "Figurageometrica.h"
///Classe putEllipsoid derivada da classe FiguraGeometrica.
///
///Uma esfera deverá ser especificada para desenho conforme a posição do centro, seus raios em pixels, bem como sua cor e transparência.
class putEllipsoid : public FiguraGeometrica
{
    int xcenter; int ycenter; int zcenter; int rx; int ry; int rz;
public:
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putEllipsoid(){};
};


#endif // PUTELLIPSOID_H_INCLUDED
