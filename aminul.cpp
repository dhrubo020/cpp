#include<iostream>
using namespace std;
class CalcRate {
    private:
    float TotalMiles=0, TotalGallons=0;

    public:
    void ShowRes(float M, float G) {
        TotalMiles = TotalMiles + M;
        TotalGallons = TotalGallons + G;
        cout<<"MPG This Tankful: "<< M/G <<endl;
        cout<<"Total MPG: "<< TotalMiles/TotalGallons <<endl;
        cout<<endl;
    }
};
int main() {
    CalcRate CR;
    float Miles, Gallons=0, Avg=1, OverallAvg=1;
    while(Miles != -1) {
        cout<<"Enter miles driven (-1 to quit): ";
        cin>>Miles;
        cout<<"Enter gallons used: ";
        cin>>Gallons;
        CR.ShowRes(Miles, Gallons);
    }
}
