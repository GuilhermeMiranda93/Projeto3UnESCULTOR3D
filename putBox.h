#ifndef PUTBOX_H_INCLUDED
#define PUTBOX_H_INCLUDED
#include "Figurageometrica.h"
#include "Sculptor.h"
#include "Voxel.h"

//Declara��o de classe herdeira
///Classe putVoxel derivada da classe FiguraGeometrica.
///
///Um voxel dever� ser especificado para desenho conforme sua posi��o no espaco, sua cor e transpar�ncia.
class putBox: public FiguraGeometrica{
    int x0, x1, y1, y0, z0,z1;

public:
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putBox(){};
    //M�todo draw
    void draw(Sculptor &t);

};


#endif // PUTBOX_H_INCLUDED
