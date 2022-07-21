#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED

#include "Figurageometrica.h"
///Classe putSphere derivada da classe FiguraGeometrica.
///
///Uma esfera deverá ser especificada para desenho conforme a posição do centro, seu raio em pixels, bem como sua cor e transparência.
class putSphere : public FiguraGeometrica
{
    int xcenter; int ycenter; int zcenter; int radius;
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putSphere(){};
};

#endif // PUTSPHERE_H_INCLUDED
