#include <iostream>
#include <vector>
#include <memory>

// Forward declaration of classes
class Instruction;

class HeaderRow {
public:
    std::vector<std::shared_ptr<Instruction>> children;

    void connect(std::shared_ptr<Instruction> instruction) {
        children.push_back(instruction);
    }
};

class Instruction {
public:
    // Add parameters as member variables
    std::vector<std::string> parameters;
};

class DFPN : public Instruction {
public:
    std::vector<std::string> channel_no;
    std::vector<std::string> pinNo;
    std::vector<std::string> pin;
};

class DFPS : public Instruction {
public:
    std::vector<std::string> dps_channel;
    std::vector<std::string> polarity;
    std::vector<std::string> pin;
};
