#pragma once

#include <fstream>
#include <string>
#include <cstring>

#include "../DataStructs/RobotSettingsStruct/RobotSettingsStruct.hpp"
#include "../DataTransmissions/Socket/Socket.hpp"
#include "../BaseProtocol/BaseProtocol.hpp"

namespace DataProtocols {
    class RobotSettingsProtocol : public BaseProtocol{
    private:
        Socket _settingSocket;

    public:
        explicit RobotSettingsProtocol();

        static RobotSettingsStruct GetSettings();

        void Start();
        void StartAsync();
    };


}