#ifndef PUTVOXEL_H_INCLUDED
#define PUTVOXEL_H_INCLUDED

#include "Figurageometrica.h"
#include "sculptor.h"
///Classe putVoxel derivada da classe FiguraGeometrica.
///
///Um voxel deverá ser especificado para desenho conforme sua posição no espaco, sua cor e transparência.
class putVoxel: public FiguraGeometrica
{
int x, y, z;
public:
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~putVoxel(){};
    void draw(Sculptor &t);
};


#endif // PUTVOXEL_H_INCLUDED
