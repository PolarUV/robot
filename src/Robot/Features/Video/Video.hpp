#ifndef ROBOT_VIDEO_HPP
#define ROBOT_VIDEO_HPP

#include <TcpSession/TcpSession.hpp>
#include <VideoStream/Gstreamer.hpp>

namespace app {

    class Video final : public lib::network::IService {
    public:

        Video(const Video&) = delete;
        Video(Video&&) = delete;
        Video& operator=(const Video&) = delete;
        Video& operator=(Video&&) = delete;

        explicit Video(ssize_t id);
        ~Video() final;
        void Write(const std::string_view &action) final;
        ResponseBufferType Read() final;

    private:
        void ConnectionLost() final;

        lib::processing::Gstreamer gstreamer_;
    };
}

#endif
