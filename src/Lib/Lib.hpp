#ifndef ROBOT_LIB_HPP
#define ROBOT_LIB_HPP

#include "./Logger/Logger.hpp"
#include "./Math/Math.hpp"
#include "./Peripheral/Peripheral.hpp"
#include "./DataTransmissions/DataTransmissions.hpp"
#include "./TcpSession/TcpSession.hpp"
#include "./VideoStream/Gstreamer.hpp"

namespace lib {
    void Initialize();
}
#endif