#ifndef ROBOT_GSTREAMER_HPP
#define ROBOT_GSTREAMER_HPP

#include <gst/gstelement.h>
#include <ostream>

namespace lib::processing {

    struct Settings{
        std::string_view Ip;
        std::string_view DeviceName;
        int FramerateEnumerator;
        int FrameDenumerator;
        int Brightness;
        int Contrast;
        int Hue;
        int Saturation;
    };

    class Gstreamer {
        GstElement *src;
        GstElement *h264parse;
        GstElement *rtp;
        GstElement *gdp;
        GstElement *sink;
        GstElement *group;

    public:
        Gstreamer();
        ~Gstreamer();

        void Start(const Settings &settings);
        void Stop();

        friend std::ostream &operator<<(std::ostream &out, const Gstreamer &gst) {

            out << "[GST STRUCTURE]"
                << "\nsrc:       " << gst.src
                << "\nh264parse: " << gst.h264parse
                << "\nrtp:       " << gst.rtp
                << "\ngdp:       " << gst.gdp
                << "\nsink:      " << gst.sink
                << "\npipeline:  " << gst.group;

            return out;
        }

        static std::string ScanCameras();

    };

}

extern "C" void InitGstreamer();

#endif
