#pragma once
#include "JournalEvent.h"

namespace Journal {
    class USSDrop : public JournalEvent
    {
    private:
        std::string type_;
        int threat_;
    public:
        USSDrop(nlohmann::json& json);
        USSDrop(std::string timestamp, std::string type, int threat);

        EventType getEventType() const { return EventType::USSDrop; }
        std::string type() const { return type_; }
        int threat() const { return threat_; }
    };
}