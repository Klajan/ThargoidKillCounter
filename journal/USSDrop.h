#pragma once
#include "JournalEvent.hpp"

namespace Journal {
    class USSDrop : public JournalEvent
    {
    private:
        std::string type;
        int threat;
    public:
        USSDrop(nlohmann::json&);
        USSDrop(std::string timestamp, std::string type, int threat);

        std::string type() const { return type; }
        int threat() const { return threat; }
    };
}