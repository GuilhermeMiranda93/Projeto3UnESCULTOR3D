#ifndef SCULPTOR_H_INCLUDED
#define SCULPTOR_H_INCLUDED

#include "Voxel.h"
///Class Sculptor contém os métodos necessários por outras classes para desenho do um objeto.
class Sculptor{

protected:
    Voxel ***v;
    int nx,ny,nz;
    float r,g,b,a;

public:
    //Método construtor
    Sculptor(int _nx, int _ny, int _nz);
    //Método destrutor
    ~Sculptor();
    //Método para definir a cor
    void setColor (float r, float g, float b, float alpha);
    //Método para adicionar um voxel
    void putVoxel (int x, int y, int z);
    //Método para retirar um voxel
    void cutVoxel (int x, int y, int z);
    //Método de escrita e geração do arquivo OFF
    int getx();
    int gety();
    int getz();
    void writeOFF(char *filename);

};


#endif // SCULPTOR_H_INCLUDED
