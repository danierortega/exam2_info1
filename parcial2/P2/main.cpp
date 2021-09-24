#include <iostream>
#include <QImage>
//#include "pruebas.h"

using namespace std;

int main()
{
    string filename="../P2/images/sudafrica25x24.png";
    QImage im(filename.c_str());

    cout<<im.width()<<"x"<<im.height()<<" pixels"<<endl;
    string matriz[im.width()][im.height()];
    //string matriz2[8][8];
    string matriz3[8][8];



   /* int contX=0;
    int contY=0;

    //if((im.width()%8)>0) resiX=1;
    //if((im.height()%8)>0) resiY=1;
        //ciclo para reducir
        for(unsigned int y=0; y < 8; y++){
            cout<<endl;
                for (unsigned int x=0; x < 8; x++){

                    matriz3[x][y]=to_string(im.pixelColor(contX,contY).red())+","+to_string(im.pixelColor(contX,contY).green())+","+to_string(im.pixelColor(contX,contY).blue());
                    cout<<matriz3[x][y]<<",";
                    contX=contX+(im.width()/8);
                }
                contY=contY+(im.height()/8);
                contX=0;
            }*/

   for(unsigned int indy=0; indy < im.height(); indy++){
        //cout<<"\n";
        for (unsigned int indx=0; indx < im.width(); indx++){

            unsigned int valorR=im.pixelColor(indx,indy).red();
            unsigned int valorG=im.pixelColor(indx,indy).green();
            unsigned int valorB=im.pixelColor(indx,indy).blue();

            /*matriz[indx][indy]=valorR;
            cout<<matriz[indx][indy]<<",";
            matriz[indx][indy]=valorG;
            cout<<matriz[indx][indy]<<",";
            matriz[indx][indy]=valorB;
            cout<<matriz[indx][indy]<<",";*/


            matriz[indx][indy]=(to_string(valorR)+","+to_string(valorG)+","+to_string(valorB)+",");
            //cout<<matriz[indx][indy]<<"/";
        }

        }

    //para mostrar
    unsigned int contX=0;
    int cont=0;
    for(unsigned int y=0; y < 8; y++){
        cout<<endl;
            for (unsigned int x=0; x < 8; x++){

                matriz3[x][y]=(matriz[contX][cont]);
                cout<<matriz3[x][y]<<" ";
                contX=contX+(im.width()/8);

            }
            cont=cont+(im.width()/8);
            contX=0;
        }

    return 0;
}
