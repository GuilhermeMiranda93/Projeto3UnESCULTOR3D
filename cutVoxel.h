#ifndef CUTVOXEL_H_INCLUDED
#define CUTVOXEL_H_INCLUDED

#include "Figurageometrica.h"
///Classe cutVoxel derivada da classe FiguraGeometrica.
///
///Um voxel dever� ser especificado para remo��o conforme sua posi��o no espa�os.
class cutVoxel:public FiguraGeometrica{
    int x; int y; int z;
public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){};
    void draw(Sculptor &t);
};


#endif // CUTVOXEL_H_INCLUDED
