//canfit.h

#ifndef _CANFIT_H_
#define _CANFIT_H_

namespace cnf{

    typedef struct {
        double length;
        double width;
    } rect;

    typedef struct {
        bool exists = false;
        bool has2 = false;
        double th1;
        double th2;
    } theta;

    class Box {
        private:
            //Class Variables
            double length;
            double width;
            double height;
        
        public:
            //Constructors
            Box(); //Constructs box with all dimensions equal to 1
            Box(double, double, double); //Constructs box with length dimension as 1st param, width as 2nd, and height as 3rd

            //Mutators
            void setLength(double);
            void setWidth(double);
            void setHeight(double);

            //Accessors
            double getLength() const;
            double getWidth() const;
            double getHeight() const;
    };

    void orient(Box&); //Function to orient the box, makes length the largest dimension, height 2nd largest, and width the smallest

    //Functions that return a rectangle of a side
    rect broadSide(Box&);
    rect topSide(Box&);

    theta determineTheta(Box&, Box&, double); //The 'holder' box should come first, then the 'held' box

}

#endif