#ifndef AEDA2020_PORTAGENS_TECHNICIAN_H
#define AEDA2020_PORTAGENS_TECHNICIAN_H

#include <string>

using namespace std;

class Technician {
    string name;
    string specialty; // revisão ; avaria(eletrónica ; informática)
    float performance; //tempo médio
    int num_intervetion;
public:
    Technician(string name, string specialty);
    string getName() const;
    void setName(string name);
    string getSpecialty() const;
    void setSpecialty(string specialty);
    float getPerformance() const;
    void setPerformance(float performance);
    int getNumIntervetion() const;
    void addIntervention();
    bool operator<(const Technician& t1) const;

};


#endif //AEDA2020_PORTAGENS_TECHNICIAN_H
