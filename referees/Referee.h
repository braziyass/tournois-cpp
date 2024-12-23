#ifndef REFEREE_H
#define REFEREE_H

#include <string>

class Referee {
public:
    Referee(const std::string& name, const std::string& certifications);
    
    std::string getName() const;
    void setName(const std::string& name);
    
    std::string getCertifications() const;
    void setCertifications(const std::string& certifications);
    
private:
    std::string name;
    std::string certifications;
};

#endif // REFEREE_H