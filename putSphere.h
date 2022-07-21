#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED

#include "Figurageometrica.h"
///Classe putSphere derivada da classe FiguraGeometrica.
///
///Uma esfera dever� ser especificada para desenho conforme a posi��o do centro, seu raio em pixels, bem como sua cor e transpar�ncia.
class putSphere : public FiguraGeometrica
{
    int xcenter; int ycenter; int zcenter; int radius;
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putSphere(){};
};

#endif // PUTSPHERE_H_INCLUDED
