#ifndef CUTBOX_H_INCLUDED
#define CUTBOX_H_INCLUDED

#include "Figurageometrica.h"
///Classe putBox derivada da classe FiguraGeometrica.
///
///Um voxel dever� ser especificado para desenho conforme sua posi��o no espaco, sua cor e transpar�ncia.
class cutBox : public FiguraGeometrica{
    int x0; int x1; int y0; int y1; int z0; int z1;
public:
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~cutBox(){};
    void draw(Sculptor &t);
};

#endif // CUTBOX_H_INCLUDED
