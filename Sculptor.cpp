#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <math.h>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  //passando as dimensões da matriz para as variáveis da classe
  nx=_nx;
  ny=_ny;
  nz=_nz;
  //Alocação dinâmica da matriz
  v = new Voxel**[nx];//Alocando os x planos

  for (int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];//Alocando as y linhas
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];//Alocando as z linhas
        }
    }
  //mudando parametro is0n:false em todas as células
   for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
          }
     }
}

Sculptor::~Sculptor(){
 //desalocando a memoria
  for(int i = 0; i<nx;i++){
    for(int j = 0; j<ny;j++){
      delete[] v[i][j];//desaloca as z linhas
    }
    delete[] v[i];//desaloca as y linhas
  }
  delete[] v;//desaloca os x planos
}

void Sculptor::setColor(float r, float g, float b, float alpha) // define a cor e transparência de cada voxel
{
//Atribui os argumentos às variáveis da classe
  this->r=r;
  r=(float)r;
  this->g=g;
  g=(float)g;
  this->b=b;
  b=(float)b;
  a=(float)alpha;
  //std::cout<< std::fixed << std::setprecision(1)<< r << g<<b<<a<<"\n";
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;

}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

int Sculptor::getx(){
    return nx;
}
int Sculptor::gety(){
    return ny;
}
int Sculptor::getz(){
    return nz;
}

void Sculptor::writeOFF(char *filename)
{
  std::ofstream fout;//cria objeto fout da classe ofstream
  int nvertices, nfaces;//variável para número de vertice e faces
  fout.open(filename);//método da fout para abrir o arquivo(e criar)
  if(!fout.is_open()){//contingência
    std::cout << "deu errado\n";
    exit(1);
  }
  //contar a quantidade de isOn==true
  int cont=0;
  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      for(int k=0;k<nz;k++){
        if(v[i][j][k].isOn==true)
          cont++;
      }
    }
  }

  nvertices = 8;//atribui 8
  nfaces = 6;//atribui 6
  fout << "OFF\n";//escreve OFF
  fout << nvertices*cont << " " << nfaces*cont << " 0\n";//escreve a quantidade total de vertices e faces*/


  for(int _i=0;_i<nx;_i++){
     for(int _j=0;_j<ny;_j++){
       for(int _k=0;_k<nz;_k++){
         if(v[_i][_j][_k].isOn==true){
           fout << _i+(-0.5) <<" "<< _j+(0.5)<<" "<<  _k+(-0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(-0.5)<<" "<< _k+(-0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(-0.5)<<" "<< _k+(-0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(0.5) <<" "<< _k+(-0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(0.5)<<" "<<  _k+(0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(-0.5)<<" "<< _k+(0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(-0.5)<<" "<< _k+(0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(0.5)<<" "<<  _k+(0.5)<<"\n";
         }
       }
     }
  }

  int voxel =0;
  for(int _i=0;_i<nx;_i++){
     for(int _j=0;_j<ny;_j++){
       for(int _k=0;_k<nz;_k++){
         if(v[_i][_j][_k].isOn==true){
           fout<< std::fixed << std::setprecision(1) <<"4 "<<(int)(0+voxel)<<" "<<(3+voxel)<<" "<<(2+voxel)<<" "<<(1+voxel)<<" "<<(float)(v[_i][_j][_k].r)<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(4+voxel)<<" "<<(5+voxel)<<" "<<(6+voxel)<<" "<<(7+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(0+voxel)<<" "<<(1+voxel)<<" "<<(5+voxel)<<" "<<(4+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(0+voxel)<<" "<<(4+voxel)<<" "<<(7+voxel)<<" "<<(3+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(3+voxel)<<" "<<(7+voxel)<<" "<<(6+voxel)<<" "<<(2+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(1+voxel)<<" "<<(2+voxel)<<" "<<(6+voxel)<<" "<<(5+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           voxel=voxel+8;
         }
       }
     }
  }

  fout.close();//fecha o arquivo
}
