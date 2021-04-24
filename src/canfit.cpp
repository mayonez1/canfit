#include <canfit.h>

#include <cmath>

using namespace cnf;

const double PI = 3.141592653;

Box::Box(){
    length = 1;
    width = 1;
    height = 1;
}

Box::Box(double l, double w, double h){
    length = l;
    width = w;
    height = h;
}

void Box::setLength(double l){
    length = l;
}

void Box::setWidth(double w){
    width = w;
}

void Box::setHeight(double h){
    height = h;
}

double Box::getLength() const{
    return length;
}

double Box::getWidth() const{
    return width;
}

double Box::getHeight() const{
    return height;
}

void cnf::orient(Box& b){
    double arr[3] {b.getLength(), b.getWidth(), b.getHeight()};
    double holder;

    for (int i = 0; i < 3; i++){
        for (int n = 0; n < 3; n++){
            if (arr[i] < arr[n]){
                holder = arr[i];
                arr[i] = arr[n];
                arr[n] = holder;
            }
        }
    }

    b.setLength(arr[2]);
    b.setHeight(arr[1]);
    b.setWidth(arr[0]);
}

rect cnf::broadSide(Box& b){
    rect ret;
    ret.length = b.getLength();
    ret.width = b.getHeight();
    return ret;
}

rect cnf::topSide(Box& b){
    rect ret;
    ret.length = b.getLength();
    ret.width = b.getWidth();
    return ret;
}

theta cnf::determineTheta(Box& holder, Box& held, double interval){
    rect holderBroad, holderTop, heldBroad, heldTop;
    theta ret;

    orient(holder);
    orient(held);

    holderBroad = broadSide(holder);
    holderTop = topSide(holder);
    heldBroad = broadSide(held);
    heldTop = topSide(held);

    /*

    if (!ret.exists){
        for (double i = 0; i < (PI/2); i += interval){
            if ((((heldBroad.length * cos(i)) + (heldBroad.width * sin(i))) <= holderBroad.length) && 
            (((heldBroad.length * sin(i)) + (heldBroad.width * cos(i))) <= holderBroad.width)){
                ret.th1 = i;
                ret.exists = true;
                break;
            }
        }
    }

    if (!ret.exists){
        for (double i = 0; i < (PI/2); i += interval){
            if ((((heldTop.length * cos(i)) + (heldTop.width * sin(i))) <= holderTop.length) && 
            (((heldTop.length * sin(i)) + (heldTop.width * cos(i))) <= holderTop.width)){
                ret.th1 = i;
                ret.exists = true;
                break;
            }
        }
    }
    */
    
    if (!ret.exists){
        for (double i = 0; i < (PI/2); i += interval){
            for (double n = 0; n < (PI/2); n += interval){
                if (((((heldBroad.length * cos(i)) + (heldBroad.width * sin(i))) * ((heldTop.length * cos(n)) + (heldTop.width * sin(n)))) <= (holderBroad.length * holderTop.length)) &&
                ((((heldBroad.length * sin(i)) + (heldBroad.width * cos(i))) * ((heldTop.length * sin(n)) + (heldTop.width * cos(n)))) <= (holderBroad.width * holderTop.width))){
                    ret.th1 = i;
                    ret.th2 = n;
                    ret.has2 = true;
                    ret.exists = true;
                    break;
                }
            }
        }
    }

    return ret;
}

