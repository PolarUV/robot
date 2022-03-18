#ifndef ROBOT_ROBOTSETTINGS_HPP
#define ROBOT_ROBOTSETTINGS_HPP

#include "Math/Static/Vector.hpp"
#include "Math/Static/Matrix.hpp"
#include "./DataTransmissions/TcpSession/TcpSession.hpp"

namespace app {

    struct RobotSettingsData {

        using Matrix_t = stc::Matrix<float, 12, 6>;
        using Vecotr_t = stc::Vector<stc::Horizontal, float, 6>;

        Matrix_t ThrustersCoefficientArray;
        Vecotr_t HandCoefficientArray;
        size_t ThrustersNumber = 0;
        size_t HandFreedom = 0;

        friend std::ostream &operator<<(std::ostream &out, const RobotSettingsData &settings) {

            out << "[MOTORS SETTINGS]\n"
                << "ThrustersNumber: " << settings.ThrustersNumber << '\n'
                << "ThrustersCoefficients:\n"
                << settings.ThrustersCoefficientArray << '\n'
                << "HandFreedom: " << settings.HandFreedom <<'\n'
                << "HandCoefficients: " << settings.HandCoefficientArray
                << std::endl;

            return out;
        }
    };

    class RobotSettings final : public lib::network::IService {
        using Response = lib::network::Response;
    public:

        RobotSettings(const RobotSettings &) = delete;

        RobotSettings(RobotSettings &&) = delete;

        RobotSettings &operator=(const RobotSettings &) = delete;

        RobotSettings &operator=(RobotSettings &&) = delete;

        RobotSettings(ssize_t id, std::string_view filename);

        bool WriteValidate(std::string_view &robotSettings) final;

        Response Write(std::string_view &robotSettings) final;

        Response Read(std::string_view &request) final;

        inline const RobotSettingsData &GetSettings() {
            return settings_;
        };

    private:
        std::string_view filename_;
        RobotSettingsData settings_;

        void GetSettingsFromDisk();
    };

}
#endif