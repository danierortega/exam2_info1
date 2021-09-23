#include <iostream>
#include <QImage>
#include "pruebas.h"

using namespace std;

int main()
{
    string filename="../P2/images/venezuela25x24.png";
    QImage im(filename.c_str());

    cout<<im.width()<<"x"<<im.height()<<" pixels"<<endl;
    unsigned long long int matriz[im.width()][im.height()];
    string matriz2[im.width()][im.height()];
    string matriz3[8][8];


    //unsigned int pixelX = im.width();
    //unsigned int pixelY = im.height();

    for(unsigned int indy=0; indy < im.height(); indy++){
        //cout<<"\n";
        for (unsigned int indx=0; indx < im.width(); indx++){

            unsigned int valorR=im.pixelColor(indx,indy).red();
            unsigned int valorG=im.pixelColor(indx,indy).green();
            unsigned int valorB=im.pixelColor(indx,indy).blue();

            matriz[indx][indy]=valorR;
            //cout<<matriz[indx][indy]<<",";
            matriz[indx][indy]=valorG;
            //cout<<matriz[indx][indy]<<",";
            matriz[indx][indy]=valorB;
            //cout<<matriz[indx][indy]<<",";


            matriz2[indx][indy]=(to_string(valorR)+","+to_string(valorG)+","+to_string(valorB)+",");
            //cout<<matriz2[indx][indy]<<"/";
        }
    }

    //para mostrar
    unsigned int contX=0, contY=0;
    for(unsigned int y=0; y < 8; y++){
        cout<<endl;
            for (unsigned int x=0; x < 8; x++){

                matriz3[x][y]=matriz2[contX+(im.width()/8)][contY+(im.height()/8)];
                cout<<matriz3[x][y]<<" ";
                contX=contX+(im.width()/8);
                contY=contY+(im.height()/8);
            }
        }


    //cilos para reducir
    /*for(int y=1; y < im.height(); y+2){
            cout<<endl;
        for (int x=1; x < im.width(); x+2){
            matriz2[x][y]="0";
            //matriz[y][x]=0;
            cout<<matriz2[x][y];

        }
    }*/

    return 0;
}
