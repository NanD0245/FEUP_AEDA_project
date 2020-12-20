#ifndef AEDA2020_PORTAGENS_TECHNICIAN_H
#define AEDA2020_PORTAGENS_TECHNICIAN_H

#include <string>

using namespace std;

class Technician {
    string name;
    string specialty; // revisão ; avaria(eletrónica ; informática)
    float performance; //tempo médio
public:
    Technician(string name, string specialty);
    string getName() const;
    void setName(string name);
    string getSpecialty() const;
    void setSpecialty(string specialty);
    float getPerformance() const;
    void setPerformance(float performance);

};


#endif //AEDA2020_PORTAGENS_TECHNICIAN_H
