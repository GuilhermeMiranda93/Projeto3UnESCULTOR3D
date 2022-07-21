#ifndef CUTSPHERE_H_INCLUDED
#define CUTSPHERE_H_INCLUDED

#include "Figurageometrica.h"
///Classe cutSphere derivada da classe FiguraGeometrica.
///
///Uma esfera dever� ser especificada para remo��o conforme a posi��o do centro e seu raio em pixels.
class cutSphere : public FiguraGeometrica{
    int xcenter; int ycenter; int zcenter; int radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
    ~cutSphere(){};
};


#endif // CUTSPHERE_H_INCLUDED
