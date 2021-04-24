#include <canfit.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv){
    const double PI = 3.141592653;

    double interval = (PI/2048);

    double x, y, z;

    cnf::Box holder;
    cnf::Box held;
    cnf::theta myTheta;

    cout << "Enter the three dimensions you would like the holder box to be: " << endl;
    cin >> x >> y >> z;
    holder.setLength(x);
    holder.setWidth(y);
    holder.setHeight(z);
    cout << "Enter the three dimensions you would like the held box to be: " << endl;
    cin >> x >> y >> z;
    held.setLength(x);
    held.setWidth(y);
    held.setHeight(z);

    myTheta = cnf::determineTheta(holder, held, interval);

    cout << "Holder: length: " << holder.getLength() << " width: " << holder.getWidth() << " height: " << holder.getHeight() << endl;
    cout << "Held: length: " << held.getLength() << " width: " << held.getWidth() << " height: " << held.getHeight() << endl;

    if (!myTheta.exists){
        cout << "Box does not fit." << endl;
    }
    else {
        cout << "Box fits at these angles: " << endl;
        cout << "Pitch: " << myTheta.th1 << " radians" << endl;
        cout << "Yaw: " << myTheta.th2 << " radians" << endl;
    }
    /*
    else {
        cout << "Box fits, angled at: " << fixed << setprecision(10) << myTheta.th1 << endl;
    }
    */

    return 0;
}
